cmake_minimum_required(VERSION 3.20)
project(link_stack C)

set(CMAKE_C_STANDARD 99)

add_executable(link_stack main.c stack.h stack.c)
