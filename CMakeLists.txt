cmake_minimum_required(VERSION 4.2)
project(FileManager)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(FileManager
        main.cpp
        FileManager.cpp
        FileManager.h
        log.cpp
        log.h
)
