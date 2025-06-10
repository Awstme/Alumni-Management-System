cmake_minimum_required(VERSION 3.31)
project(Alumni_Management_System)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")


include_directories(include)

add_executable(Alumni_Management_System
        include/alumni.h
        include/alumni_list.h
        include/alumni_manager.h
        src/alumni.cpp
        src/alumni_list.cpp
        src/main.cpp)
