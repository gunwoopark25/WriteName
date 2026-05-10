cmake_minimum_required(VERSION 3.10)

project(WriteName)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(WriteName
        main.cpp
        WriteName.cpp
)