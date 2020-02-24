cmake_minimum_required(VERSION 3.15)
project(premierProg)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_PATH /usr/include/cairo)
set(CMAKE_INCLUDE_PATH /usr/include/gtk+-3.0)
set(CMAKE_INCLUDE_PATH /usr/include/librsvg-2.0)
set(CMAKE_INCLUDE_PATH /usr/include/tinyxml2)

add_executable(premierProg test.cpp)