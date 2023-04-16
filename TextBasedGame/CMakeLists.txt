cmake_minimum_required(VERSION 3.16)

project(TextBasedGame)

set(CMAKE_CXX_STANDARD 11)

include(soloud/contrib/CMakeLists.txt)


# Add source files
set(SOURCES
    src/achievements/achievement.cpp
    src/achievements/achievement.h
    src/achievements/achievement_collection.cpp

    src/command/command.cpp
    src/command/command.h
    
    src/item/item.cpp
    src/item/item.h
    src/item/terminal.cpp
    src/item/note.cpp
    
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
    
    src/day/day.h
    src/day/day.cpp
    
    src/mission/mission.h
    src/mission/mission.cpp
    
    src/progress/progress.h
    src/progress/progress.cpp
    
    src/utils/prompt.cpp
    src/utils/prompt.h
    src/utils/game_utils.h
    src/utils/game_utils.cpp
    
    src/sound/sound.h
    src/sound/sound.cpp

    src/main.cpp
)

message("SoLoud: ${SOLOUD_SRC}")

option(WITH_SDL2 "Enable SDL2 audio backend" OFF)
set(WITH_SDL2_DYNAMIC FALSE CACHE BOOL "Build SDL2 dynamically")
set(WITH_SDL2_STATIC FALSE CACHE BOOL "Build SDL2 statically")

message("WITH_SDL2: ${WITH_SDL2}")

add_executable(TextBasedGame ${SOURCES})
target_link_libraries(TextBasedGame soloud)


