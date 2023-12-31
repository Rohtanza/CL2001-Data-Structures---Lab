cmake_minimum_required(VERSION 3.26)
project(BooksManagementSystem)

set(CMAKE_CXX_STANDARD 23)

add_executable(BooksManagementSystem main.cpp
        DoublyLinkedList.h
        Date.h
        Book.h
        BookManagementSystem.h)
