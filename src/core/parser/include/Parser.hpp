#pragma once
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <string_view>

namespace Arcade
{
    const std::string_view GRAPHICS_LIBRARIES[] = {
        "./lib/arcade_ncurses.so",
        "./lib/arcade_sdl2.so",
        "./lib/arcade_ndk++.so",
        "./lib/arcade_aalib.so",
        "./lib/arcade_libcaca.so",
        "./lib/arcade_allegro5.so",
        "./lib/arcade_xlib.so",
        "./lib/arcade_gtk+.so",
        "./lib/arcade_sfml.so",
        "./lib/arcade_irrlicht.so",
        "./lib/arcade_opengl.so",
        "./lib/arcade_vulkan.so",
        "./lib/arcade_qt5.so",
    };

    const std::string_view GAMES_LIBRARIES[] = {
        "./lib/arcade_nibbler.so",
        "./lib/arcade_pacman.so",
        "./lib/arcade_qix.so",
        "./lib/arcade_centipede.so",
        "./lib/arcade_solarfox.so",
        "./lib/arcade_snake.so",
    };

    // the parser must be able to read all .so files in the lib folder
    class Parser {
      public:
        Parser(std::string defaultPath);
        ~Parser() {
            std::cout << "Parser destroyed" << std::endl;
        };

        // return a vector of all the .so files in the lib folder
        bool reload();

        std::vector<std::string> getGames();
        std::vector<std::string> getGraphics();

      private:
        std::string _defaultPath;
        std::vector<std::string> _games;
        std::vector<std::string> _graphics;
        std::vector<std::string> _libs;
    };
} // namespace Arcade
