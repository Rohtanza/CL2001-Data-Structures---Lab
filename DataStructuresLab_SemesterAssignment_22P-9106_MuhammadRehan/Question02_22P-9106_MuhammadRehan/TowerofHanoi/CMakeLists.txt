cmake_minimum_required(VERSION 3.26)
project(TowerofHanoi)

set(CMAKE_CXX_STANDARD 23)

add_executable(TowerofHanoi main.cpp
        Disk.h
        Node.h
        Stack.h
)
