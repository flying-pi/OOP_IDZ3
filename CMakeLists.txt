cmake_minimum_required(VERSION 3.6)
project(OOP_IDZ3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES MAINMATRFILE.cpp MATRFILE.h MYMATRIX.cpp)
add_executable(OOP_IDZ3 ${SOURCE_FILES})