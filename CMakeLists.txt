cmake_minimum_required(VERSION 3.31)
project(Alumni_Management_System)

set(CMAKE_CXX_STANDARD 14)

add_executable(Alumni_Management_System
        src/main.cpp
        src/person.cpp
        src/person.h
        src/alumni.cpp
        src/alumni.h
        src/AlumniList.cpp
        src/AlumniList.h
        src/menu.cpp
        src/menu.h
)
