cmake_minimum_required(VERSION 3.26)
project(HeapTask)

set(CMAKE_CXX_STANDARD 23)

add_executable(HeapTask main.cpp
        Patient.h
        Heap.h)
