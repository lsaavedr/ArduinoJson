// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

#include <float.h>

namespace ArduinoJson {
namespace Polyfills {

template <typename T>
bool isNaN(T x) {
  return _isnan(x) != 0;
}
}
}
