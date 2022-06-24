cmake_minimum_required(VERSION 3.22)
project(CGalgo)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include)
include_directories(~/Documents/environments/glad/include)
link_directories(/usr/local/lib)

link_libraries("-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")

add_executable(CGalgo main.cpp glad.c dda.cpp)
target_link_libraries(CGalgo glfw3)