cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

project(TextBasedGame)

set(LIB_CMAKE_PATH "Text-Based-Game-Engine/Engine/CMakeLists.txt")

include(${LIB_CMAKE_PATH})
include("./src/mastermind/CMakeLists.txt")


# Add source files
set(SOURCES
    src/main.cpp

    src/achievements/achievement_collection.h
    src/achievements/achievement_collection.cpp

    src/map/map.h
    src/map/map.cpp
    src/map/node_setup.h
    src/map/node_setup.cpp

    src/items/items.h
    src/items/inventory.cpp
    src/items/Terminal.cpp
    src/items/Note.cpp
    src/items/Door.cpp
    src/items/Bed.cpp
    src/items/File.cpp
    src/items/Board.cpp
    src/items/Safe.cpp

    src/day/day.h
    src/day/day1.cpp
    src/day/day2.cpp

    src/menu/menu.h
    src/menu/menu.cpp
    
    src/command/command.h
    src/command/command.cpp
    src/command/terminal_command.h
    src/command/terminal_command.cpp

    src/interactions/interactions.h
    src/interactions/interactions.cpp
)

add_executable(TextBasedGame ${SOURCES})
target_link_libraries(TextBasedGame TextBasedGameEngine)
target_link_libraries(TextBasedGame MastermindMinigame)
