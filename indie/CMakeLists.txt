cmake_minimum_required(VERSION 3.17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(raylib REQUIRED)

project(bomberman)
set (SRC
    indie.cpp
    Graphical/handle_path.cpp
    Graphical/Bomb.cpp
    Graphical/Button.cpp
    Graphical/Menu.cpp
    Graphical/Model.cpp
    Graphical/Option.cpp
    Graphical/Player.cpp
    Graphical/Raylib.cpp
    Graphical/Sound.cpp
    Graphical/Texture.cpp
)
add_executable(bomberman
    ${SRC}
)

target_include_directories(bomberman PUBLIC ${CMAKE_SOURCE_DIR}/Graphical/)
include_directories(RAYLIB/src)
target_link_libraries(bomberman raylib)