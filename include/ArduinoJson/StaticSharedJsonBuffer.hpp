// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

#include "JsonBuffer.hpp"

namespace ArduinoJson {

// Implements a JsonBuffer with fixed shared memory allocation.
// The template paramenter 'capacity' specifies the
// capacity of the 'buffer' in bytes.
class StaticSharedJsonBuffer : public JsonBuffer {
 public:
  explicit StaticSharedJsonBuffer(uint8_t* buffer, size_t capacity) :
    _buffer(buffer), _capacity(capacity), _size(0) {}

  size_t capacity() const { return _capacity; }
  size_t size() const { return _size; }

  virtual void* alloc(size_t bytes) {
    if (_size + bytes > _capacity) return NULL;
    void* p = &_buffer[_size];
    _size += round_size_up(bytes);
    return p;
  }

 private:
  uint8_t* _buffer;
  size_t _capacity;
  size_t _size;
};
}
