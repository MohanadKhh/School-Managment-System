cmake_minimum_required(VERSION 3.26)
project(School_Management_System C)

set(CMAKE_C_STANDARD 11)

add_executable(School_Management_System main.c
        stack.c
        stack.h
        students.c
        students.h
        list.c
        list.h)
