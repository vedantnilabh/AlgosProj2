cmake_minimum_required(VERSION 3.23)
project(AlgosProj2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AlgosProj2
        MyGraph.cpp
        MyGraph.h
        prog2test.cpp)
