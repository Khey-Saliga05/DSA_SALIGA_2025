cmake_minimum_required(VERSION 4.0)
project(DSA_SALIGA C)

set(CMAKE_C_STANDARD 11)

add_executable(DSA_SALIGA main.c
        linked_list.h
        linked_list.c
        stack.c
        stack.h
        queue.c
        queue.h
)
