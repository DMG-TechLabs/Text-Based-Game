cmake_minimum_required(VERSION 3.16)
	
include(Text-Based-Game-Engine/Engine/CMakeLists.txt)

project(TextBasedGame)

set(CMAKE_CXX_STANDARD 11)


# Add source files
set(SOURCES
    src/main.cpp
)

add_executable(TextBasedGame ${SOURCES})
target_link_libraries(TextBaseGame TextBaseGameEngine)
