cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

project(TextBasedGame)

set(LIB_CMAKE_PATH "Text-Based-Game-Engine/Engine/CMakeLists.txt")

include(${LIB_CMAKE_PATH})


if (UNIX)
    set(MENU
        src/menu/menu_utils_unix.cpp
    )        
endif(UNIX)

if(WIN32)
    set(MENU
        src/menu/menu_utils_win.cpp
    )
endif(WIN32)

# Add source files
set(SOURCES
    src/main.cpp

    src/achievements/achievement_collection.h
    src/achievements/achievement_collection.cpp

    src/mission/mission.h
    src/mission/mission.cpp
    src/mission/Objective.h
    src/mission/Objective.cpp

    src/map/map.h
    src/map/map.cpp

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
    src/day/demo.cpp

    src/menu/menu.h
    src/menu/menu.cpp
    src/menu/menu_utils.h
    
    src/command/command.h
    src/command/command.cpp
    src/command/terminal_command.h
    src/command/terminal_command.cpp

    src/interactions/interactions.h
    src/interactions/interactions.cpp
)

add_executable(TextBasedGame ${SOURCES} ${MENU})
target_link_libraries(TextBasedGame TextBasedGameEngine)
