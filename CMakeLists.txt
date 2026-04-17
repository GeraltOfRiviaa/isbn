cmake_minimum_required(VERSION 4.0)
project(isbn)

set(CMAKE_CXX_STANDARD 23)

add_executable(isbn main.cpp
        ISBN.cpp
        ISBN.h)
