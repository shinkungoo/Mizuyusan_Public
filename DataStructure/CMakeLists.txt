cmake_minimum_required(VERSION 3.22)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStructure main.c test.h link_list.h link_list.c "linear_list\; .h" ring_queue.h deque.h linear_stack.h link_queue.h link_stack.h)
