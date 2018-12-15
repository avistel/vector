cmake_minimum_required(VERSION 3.7)
project(cvector C)

set(CMAKE_C_STANDARD 99)

enable_testing()

include_directories(include)

add_library(cvector src/vector.c include/vector.h)

add_executable(unittests src/vector.c tests/test.c)