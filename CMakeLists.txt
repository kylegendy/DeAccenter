cmake_minimum_required(VERSION 3.19)
project(DeAccenter)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(DeAccenter
        include/DeAccenter.h
        src/DeAccenter.cpp
        test/test.cpp)
