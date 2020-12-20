# https://www.hahack.com/codes/cmake/
cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(readelf elf/hello.c elf/readelf.c)
add_executable(1.1 easy/1.1.cpp)
add_executable(2.1 easy/2.1.cpp)
add_executable(4.1 easy/4.1.cpp)
add_executable(5.1 easy/5.1.cpp)
add_executable(5.2 easy/5.2.cpp)
add_executable(6.1 easy/6.1.cpp)
