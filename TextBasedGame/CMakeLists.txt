cmake_minimum_required(VERSION 3.16)

project(TextBasedGame)

set(CMAKE_CXX_STANDARD 11)


# Add source files
set(SOURCES
    src/achievements/achievement.cpp
    src/achievements/achievement.h
    src/achievements/achievement_collection.cpp

    src/command/command.h
    
    src/item/item.cpp
    src/item/item.h
    
    src/player/inventory.cpp
    src/player/inventory.h
    src/player/movement.cpp
    src/player/movement.h
    src/player/player.cpp
    src/player/player.h
    
    src/map/node.cpp
    src/map/node.h
    src/map/map.cpp
    src/map/map.h
    
    src/progress/progress.h
    src/progress/progress.cpp
    
    src/utils/prompt.cpp
    src/utils/prompt.h
    src/utils/game_utils.h
    src/utils/game_utils.cpp

    src/main.cpp
)



add_executable(TextBasedGame ${SOURCES})


