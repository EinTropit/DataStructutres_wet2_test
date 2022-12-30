cmake_minimum_required(VERSION 3.22)
project(DS2_test)

set(CMAKE_CXX_STANDARD 11)

add_executable(DS2_test unit_tests/catch.hpp unit_tests/WorldCupTests.cpp unit_tests/wet2util_override.h)
