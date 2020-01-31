cmake_minimum_required(VERSION 3.8)
project(AT_demo)

set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(AT_demo main.cpp hello.cpp)