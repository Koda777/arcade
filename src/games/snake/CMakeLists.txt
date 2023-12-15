cmake_minimum_required(VERSION 3.10)

project(arcade_games)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(INCLUDE_DIRS include ../controller/include/)

include_directories(${INCLUDE_DIRS})

set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(SOURCE_FILES
  ../controller/src/Game.cpp
  src/Snake.cpp
  src/SnakeGame.cpp
  src/Fruit.cpp
)

add_library(arcade_snake SHARED ${SOURCE_FILES})

target_compile_options(arcade_snake PRIVATE -Wall -Wextra -std=c++20 -g)

set_target_properties(arcade_snake PROPERTIES
    OUTPUT_NAME arcade_snake
    LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/lib/
    SUFFIX ".so"
)
