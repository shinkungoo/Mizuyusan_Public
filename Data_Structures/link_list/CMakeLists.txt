cmake_minimum_required(VERSION 3.20)
project(link_list C)

set(CMAKE_C_STANDARD 99)

add_executable(link_list main.c list.h list.c)
