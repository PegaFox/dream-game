cmake_minimum_required(VERSION 3.7)

project(RPG-game)

add_executable(RPG_game main.cpp)

target_link_libraries(RPG_game sfml-graphics sfml-window sfml-system)