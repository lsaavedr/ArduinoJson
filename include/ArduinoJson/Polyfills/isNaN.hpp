// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

// If Visual Studo <= 2012
#if defined(_MSC_VER) && _MSC_VER <= 1700
#include "isNaN.vs2012.hpp"

// If C++11 or above
#elif __cplusplus >= 201103
#include "isNaN.cpp11.hpp"

// Otherwise
#else
#include "isNaN.default.hpp"
#endif
