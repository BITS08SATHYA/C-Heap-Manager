cmake_minimum_required(VERSION 3.31)
project(heap_memory)

set(CMAKE_CXX_STANDARD 20)

add_executable(heap_memory main.cpp
        mm.c)
