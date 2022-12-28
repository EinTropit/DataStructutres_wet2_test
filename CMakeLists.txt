cmake_minimum_required(VERSION 3.22)
project(DS2_test)

set(CMAKE_CXX_STANDARD 11)

add_executable(DS2_test catch.hpp WorldCupTests.cpp)
