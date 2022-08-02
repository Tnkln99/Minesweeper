cmake_minimum_required(VERSION 3.22)
project(Minesweeper)

find_package(SFML 2.5 COMPONENTS network graphics audio REQUIRED)

add_library(scrLib
        scr/Board.cpp
        scr/Game.cpp
        scr/Button.cpp
        scr/MenuWindow.cpp scr/GameWindow.cpp)

target_link_libraries(scrLib PRIVATE sfml-network sfml-graphics sfml-audio)

add_executable(Minesweeper scr/main.cpp)
target_link_libraries(Minesweeper scrLib)
