cmake_minimum_required(VERSION 3.10)

project(arcade_ncurses)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(INCLUDE_DIRS
  Display/include
  Event/include
  Music/include
  Texture/include
  Controller/include
  ../Gfx/Display/include
  ../Gfx/Event/include
  ../Gfx/Music/include
  ../Gfx/Texture/include
  ../Gfx/Controller/include
)

include_directories(${INCLUDE_DIRS})

set(SOURCE_FILES
  ../Gfx/Display/src/Display.cpp
  ../Gfx/Event/src/Event.cpp
  ../Gfx/Controller/src/GfxController.cpp
  Display/src/NcursesDisplay.cpp
  Event/src/NcursesEvent.cpp
  Controller/src/NcursesController.cpp
)

add_library(arcade_ncurses SHARED ${SOURCE_FILES})

target_compile_options(arcade_ncurses PUBLIC -v -Wall -Wextra)
target_link_libraries(arcade_ncurses PUBLIC ncurses)

set_target_properties(arcade_ncurses PROPERTIES
    OUTPUT_NAME arcade_ncurses
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/
    SUFFIX ".so"
)
