cmake_minimum_required(VERSION 4.2)
project(FileManager)

set(CMAKE_CXX_STANDARD 20)

find_package(Curses REQUIRED)

add_executable(FileManager
        main.cpp
        FileManager.cpp
        FileManager.h
        log.cpp
        log.h
        ncurses.cpp
        ncurses.h
)

target_include_directories(FileManager PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(FileManager PRIVATE ${CURSES_LIBRARIES})