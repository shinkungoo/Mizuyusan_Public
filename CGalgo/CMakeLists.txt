cmake_minimum_required(VERSION 3.20)
project(CGalgo)

set(CMAKE_CXX_STANDARD 14)

if(WIN32)
    include_directories("D:/Environments/OpenGL/include")
    link_directories("D:/Environments/OpenGL/lib")
    add_executable(CGalgo main.cpp glad_WIN32.c)
elseif(APPLE)
    include_directories(/usr/local/include)
    include_directories(~/Documents/environments/glad/include)
    link_directories(/usr/local/lib)
    link_libraries("-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")
    add_executable(CGalgo main.cpp glad_APPLE.c utility_graphics.h utility_graphics.cpp)
endif()

target_link_libraries(CGalgo glfw3)