cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

project(TextBasedGame)

set(LIB_CMAKE_PATH "Text-Based-Game-Engine/Engine/CMakeLists.txt")

include(${LIB_CMAKE_PATH})


# Add source files
set(SOURCES
    src/main.cpp

    src/achievement_collection.cpp

    src/text/text.h
    src/text/text.cpp

    src/mission/mission.h
    src/mission/mission.cpp

    src/map/map.h
    src/map/map.cpp

    src/items/items.h
    src/items/Terminal.cpp
    src/items/Note.cpp

    src/day/day.h
    src/day/day.cpp

    # src/command/command.h
    # src/command/command.cpp
)

add_executable(TextBasedGame ${SOURCES})
target_link_libraries(TextBasedGame TextBasedGameEngine)
