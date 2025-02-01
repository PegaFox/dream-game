cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)

project(RPG-game)

add_executable(RPG_game main.cpp player.cpp room.cpp world.cpp gui_classes/window.cpp gui_classes/text.cpp gui_classes/button.cpp gui_classes/rect.cpp)

target_link_libraries(RPG_game sfml-graphics sfml-window sfml-system)