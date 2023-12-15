#pragma once
#include "../../games/controller/include/IGame.hpp"
#include "../../graphics/Gfx/Controller/include/IGfxController.hpp"
#include "../../graphics/Gfx/Display/include/IDisplay.hpp"
#include "../../graphics/Gfx/Event/include/IEvent.hpp"
#include "../../graphics/Gfx/Music/include/IMusic.hpp"
#include "../../graphics/Gfx/Texture/include/ITexture.hpp"
#include "../parser/include/Parser.hpp"

namespace Arcade
{
    class Library {
      public:
        Library(const std::string &filename);
        ~Library();
        void *load_symbol(const std::string &symbol);
        bool changeLib(const std::string &filename);
        std::string getFilename() const;
        bool close();

      private:
        void *handle_ = nullptr;
        std::string filename_;
    };

    class Core {
      public:
        Core(std::string defaultPath);
        ~Core();
        void reloadGame();
        void reloadGraphic();
        void runGraphic();

        void setUsername(const std::string &username);
        const std::string &getUsername() const;

        bool nextGame();
        bool prevGame();
        bool nextGraphic();
        bool prevGraphic();
        bool exitAll(void) const;

        // save
        bool saveData() const;
        bool loadData();

        typedef struct GraphicsType_t {
            std::unique_ptr<IEvent> event;
            std::unique_ptr<IMusic> music;
            std::unique_ptr<IDisplay> display;
            std::unique_ptr<ITexture> texture;
            std::unique_ptr<IGfxController> controller;
        } GraphicsType_s;

      private:
        Arcade::Parser _parser;
        Arcade::Library _graphic;
        Arcade::Library _game;
        std::unique_ptr<IGame> _gameInstance;
        std::unique_ptr<GraphicsType_s> _graphicInstance;
        std::string _username;
    };
} // namespace Arcade
