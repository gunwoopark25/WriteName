cmake_minimum_required(VERSION 3.10)

project(WriteName_Using_Interpolation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(WriteName_Using_Interpolation
        main.cpp
        WriteName.cpp
        Point2D.h
)