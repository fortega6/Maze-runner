cmake_minimum_required(VERSION 3.8)
project(mazerunner)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        a1q2.cpp
        a1q2main.cpp
        maze.cpp
        maze.h)

add_executable(mazerunner ${SOURCE_FILES})