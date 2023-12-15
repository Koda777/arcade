cmake_minimum_required(VERSION 3.10)

project(arcade_nibbler)

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
  src/Nibbler.cpp
  src/NibblerGame.cpp
  src/Fruit.cpp
)

add_library(arcade_nibbler SHARED ${SOURCE_FILES})

target_compile_options(arcade_nibbler PRIVATE -Wall -Wextra -std=c++20 -g)

set_target_properties(arcade_nibbler PROPERTIES
    OUTPUT_NAME arcade_nibbler
    LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/lib/
    SUFFIX ".so"
)
