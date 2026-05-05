cmake_minimum_required(VERSION 4.1)
project(a_bugs_life)

set(CMAKE_CXX_STANDARD 20)

add_executable(a_bugs_life main.cpp
        Bug.cpp
        Bug.h
        Hopper.cpp
        Hopper.h
        Board.cpp
        Board.h
        Crawler.cpp
        Crawler.h
        Backtracker.cpp
        Backtracker.h)
