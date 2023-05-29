cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

project(MastermindMinigame)

set(SOURCES
    src/mastermind/ui/controls.h
    src/mastermind/ui/controls.cpp

    src/mastermind/game/game.h
    src/mastermind/game/game.cpp
    
    src/mastermind/game/checks.h
    src/mastermind/game/checks.cpp
)

add_library(MastermindMinigame ${SOURCES})