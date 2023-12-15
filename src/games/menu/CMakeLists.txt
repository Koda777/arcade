cmake_minimum_required(VERSION 3.10)

project(arcade_menu)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(INCLUDE_DIRS
../controller/include/
include/
)

include_directories(${INCLUDE_DIRS})

set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(SOURCE_FILES
  ../controller/src/Game.cpp
  src/MenuGame.cpp
  src/Parser.cpp
)

add_library(arcade_menu SHARED ${SOURCE_FILES})

target_compile_options(arcade_menu PRIVATE -Wall -Wextra -std=c++20 -g)

set_target_properties(arcade_menu PROPERTIES
    OUTPUT_NAME arcade_menu
    LIBRARY1_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/lib/
    SUFFIX ".so"
)
