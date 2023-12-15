cmake_minimum_required(VERSION 3.10)

project(ArcadeLibrairy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}
  /ArcadeLibrairy/include
)
set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Parser/include)
set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_PATH})

set(SOURCE_FILES
    Library/src/Library.cpp
    parser/src/Parser.cpp
    Core.cpp
    ../main.cpp
)

add_executable(arcade ${SOURCE_FILES})

target_compile_options(arcade PRIVATE -Wall -Wextra -Werror -fpic -g)

set_target_properties(arcade PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)
