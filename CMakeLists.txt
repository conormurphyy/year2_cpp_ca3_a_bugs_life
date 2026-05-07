cmake_minimum_required(VERSION 4.1)
project(a_bugs_life)

set(CMAKE_CXX_STANDARD 20)

add_executable(a_bugs_life main.cpp
        bugs/Bug.cpp
        bugs/Bug.h
        bugs/Hopper/Hopper.cpp
        bugs/Hopper/Hopper.h
        Board/Board.cpp
        Board/Board.h
        bugs/Crawler/Crawler.cpp
        bugs/Crawler/Crawler.h
        bugs/Backtracker/Backtracker.cpp
        bugs/Backtracker/Backtracker.h
        bugs/CrazyBug/CrazyBug.cpp
        bugs/CrazyBug/CrazyBug.h)
