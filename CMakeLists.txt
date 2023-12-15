cmake_minimum_required(VERSION 3.10)

project(Arcade)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/core/ArcadeLibrairy/include)

add_subdirectory(src/core)
add_subdirectory(src/graphics/ncurses)
add_subdirectory(src/graphics/sfml)
add_subdirectory(src/graphics/sdl)
add_subdirectory(src/games/nibbler)
add_subdirectory(src/games/snake)
add_subdirectory(src/games/menu)

add_custom_target(
    lib_games
    DEPENDS controller nibbler snake menu
)

add_custom_target(
    lib_graphicals
    DEPENDS Gfx ncurses sfml sdl
)
