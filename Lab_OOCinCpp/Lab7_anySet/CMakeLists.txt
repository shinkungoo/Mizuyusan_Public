cmake_minimum_required(VERSION 3.20)
project(anySet)

set(CMAKE_CXX_STANDARD 14)

add_executable(anySet main.cpp anytype.cpp anySet.cpp anytype.h anySet.h)
