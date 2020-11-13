cmake_minimum_required(VERSION 3.17)
project(Logger1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Logger1
        main.cpp
        logger.h
        logger.cpp)