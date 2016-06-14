# Copyright Benoit Blanchon 2014-2016
# MIT License
# 
# Arduino JSON library
# https://github.com/bblanchon/ArduinoJson
# If you like this project, please add a star!

include(gtest.cmake)

file(GLOB TESTS_FILES *.hpp *.cpp)

add_executable(ArduinoJsonTests ${TESTS_FILES})
target_link_libraries(ArduinoJsonTests ArduinoJson gtest)

add_test(ArduinoJsonTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ArduinoJsonTests)
