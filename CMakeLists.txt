cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(TextBasedGame)

add_subdirectory(Text-Based-Game-Engine)
include_directories(Text-Based-Game-Engine)

add_subdirectory(Mastermind-Minigame)
include_directories(Mastermind-Minigame)

include_directories(include)

# Add source files
set(SOURCES
    src/main.cpp

    src/achievements/achievement_collection.cpp

    src/map/map.cpp
    src/map/node_setup.cpp

    src/items/inventory.cpp
    src/items/Terminal.cpp
    src/items/Note.cpp
    src/items/Door.cpp
    src/items/Bed.cpp
    src/items/File.cpp
    src/items/Board.cpp
    src/items/Safe.cpp

    src/day/day1.cpp
    src/day/day2.cpp

    src/menu/menu.cpp
    
    src/command/command.cpp
    src/command/terminal_command.cpp

    src/interactions/interactions.cpp
)

set(HEADERS
    include/achievement_collection.h
    include/interactions.h
    include/terminal_command.h
    include/command.h
    include/menu.h
    include/day.h
    include/items.h
    include/node_setup.h
    include/map.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} TextBasedGameEngine)
target_link_libraries(${PROJECT_NAME} MastermindMinigame)
