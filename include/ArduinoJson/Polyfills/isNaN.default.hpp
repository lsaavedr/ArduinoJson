// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

#include <math.h>

namespace ArduinoJson {
namespace Polyfills {

template <typename T>
bool isNaN(T x) {
  return isnan(x);
}

#ifdef __GLIBC__
template <>
inline bool isNaN<double>(double x) {
  return isnanl(x);
}

template <>
inline bool isNaN<float>(float x) {
  return isnanf(x);
}
#endif
}
}
