cmake_minimum_required(VERSION 3.10)

project(arcade_sdl2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(INCLUDE_DIRS
../Gfx/Display/include
../Gfx/Controller/include
../Gfx/Event/include
  Display/include
  Controller/include
  Event/include
)

include_directories(${INCLUDE_DIRS})

set(SOURCE_FILES
  ../Gfx/Display/src/Display.cpp
  ../Gfx/Controller/src/GfxController.cpp
  ../Gfx/Event/src/Event.cpp
  Display/src/SdlDisplay.cpp
  Controller/src/SdlController.cpp
  Event/src/SdlEvent.cpp
)

add_library(arcade_sdl2 SHARED ${SOURCE_FILES})

target_compile_options(arcade_sdl2 PRIVATE -v -Wall -Wextra)

target_link_libraries(arcade_sdl2 PRIVATE SDL2 SDL2_ttf)

set_target_properties(arcade_sdl2 PROPERTIES
    OUTPUT_NAME arcade_sdl2
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/
    SUFFIX ".so"
)
