cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

project(TextBasedGame)

set(LIB_CMAKE_PATH "Text-Based-Game-Engine/Engine/CMakeLists.txt")

include(${LIB_CMAKE_PATH})


# Add source files
set(SOURCES
    src/main.cpp
)

add_executable(TextBasedGame ${SOURCES})
target_link_libraries(TextBasedGame TextBasedGameEngine)
