cmake_minimum_required(VERSION 3.20)
project(snake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lncurses")

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if (LINUX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ltinfo")
endif ()

add_executable(snake src/Snake.cpp src/Field.cpp src/Interface.cpp src/Game.cpp main.cpp)
