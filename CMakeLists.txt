cmake_minimum_required(VERSION 3.30)

#include(ExternalProject)

set(CMAKE_CXX_STANDARD 20)

project(RPG-game)

add_subdirectory(gui-lib)

add_executable(RPG_game main.cpp item.cpp player.cpp room.cpp world.cpp)

target_link_libraries(RPG_game sfml-graphics sfml-window sfml-system gui-lib)
