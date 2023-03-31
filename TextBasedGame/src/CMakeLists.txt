cmake_minimum_required(VERSION 3.0.0)
project(TextBasedGame VERSION 0.1.0)

file(GLOB TextBasedGame_SRC "*.h" "*.cpp")


include(CTest)
enable_testing()

add_executable(TextBasedGame main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
