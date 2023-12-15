cmake_minimum_required(VERSION 3.10)

project(arcade_sfml)

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
   Display/src/SfmlDisplay.cpp
   Controller/src/SfmlController.cpp
   Event/src/SfmlEvent.cpp
)

add_library(arcade_sfml SHARED ${SOURCE_FILES})

target_compile_options(arcade_sfml PRIVATE -v -Wall -Wextra)

target_link_libraries(arcade_sfml PRIVATE sfml-graphics sfml-window sfml-system)

set_target_properties(arcade_sfml PROPERTIES
    OUTPUT_NAME arcade_sfml
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/
    SUFFIX ".so"
)
