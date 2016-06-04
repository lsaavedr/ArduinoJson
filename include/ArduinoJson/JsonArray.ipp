// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

#include "JsonArray.hpp"
#include "JsonObject.hpp"
#include "JsonArraySubscript.hpp"

namespace ArduinoJson {

inline JsonArraySubscript JsonArray::operator[](size_t index) {
  return JsonArraySubscript(*this, index);
}

inline JsonVariant JsonArray::operator[](size_t index) const {
  return get(index);
}

template <>
inline bool JsonArray::setNodeValue(node_type *node, String &value) {
  const char *copy = _buffer->strdup(value);
  if (!copy) return false;
  node->content = copy;
  return true;
}

template <typename TImplem>
inline const JsonArraySubscript JsonVariantBase<TImplem>::operator[](
    int index) const {
  return asArray()[index];
}

template <>
inline JsonArray &JsonVariant::defaultValue<JsonArray &>() {
  return JsonArray::invalid();
}

template <>
inline JsonArray const &JsonVariant::defaultValue<JsonArray const &>() {
  return JsonArray::invalid();
}

inline JsonArray &JsonVariant::asArray() const {
  if (_type == Internals::JSON_ARRAY) return *_content.asArray;
  return JsonArray::invalid();
}

inline JsonArray &JsonArray::createNestedArray() {
  if (!_buffer) return JsonArray::invalid();
  JsonArray &array = _buffer->createArray();
  add(array);
  return array;
}

inline JsonArray &JsonObject::createNestedArray(JsonObjectKey key) {
  if (!_buffer) return JsonArray::invalid();
  JsonArray &array = _buffer->createArray();
  setNodeAt<const JsonVariant &>(key, array);
  return array;
}

inline void JsonArray::writeTo(Internals::JsonWriter &writer) const {
  writer.beginArray();

  const node_type *child = _firstNode;
  while (child) {
    child->content.writeTo(writer);

    child = child->next;
    if (!child) break;

    writer.writeComma();
  }

  writer.endArray();
}
}
