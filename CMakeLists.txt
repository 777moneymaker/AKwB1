cmake_minimum_required(VERSION 3.15)
project(akwb1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Libraries)

add_executable(akwb1
        cmake-build-debug/graph.txt
        Libraries/Graph.cpp
        Libraries/Graph.hpp
        LICENSE
        main.cpp
        README.md)
