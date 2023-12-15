#include "./include/core.hpp"
#include <chrono>
#include <fstream>
#include <memory>
#include <thread>
#include "../graphics/Gfx/Display/include/IDisplay.hpp"

typedef std::unique_ptr<IGame> (*create_func_game)();
typedef std::unique_ptr<IGfxController> (*create_func_gfx)();

Arcade::Core::Core(std::string defaultPath)
    : _parser("./lib"), _graphic(defaultPath), _game(_parser.getGames()[0])
{
    loadData();
    std::cout << "Core created" << std::endl;
}

Arcade::Core::~Core()
{
    saveData();
}

void Arcade::Core::reloadGame()
{
    create_func_game create;
    std::cout << "Init " << _game.getFilename() << std::endl;
    create = reinterpret_cast<create_func_game>(_game.load_symbol("factory"));
    std::unique_ptr<IGame> game = create();
    _gameInstance = std::move(game);
    _gameInstance->start(_graphicInstance->controller);
}

void Arcade::Core::reloadGraphic()
{
    create_func_gfx create;

    if (_graphicInstance != nullptr) {
        if (_graphicInstance->controller != nullptr) {
            _graphicInstance->controller.reset();
        }
        if (_graphicInstance->display != nullptr) {
            _graphicInstance->display.reset();
        }
        if (_graphicInstance->event != nullptr) {
            _graphicInstance->event.reset();
        }
        if (_graphicInstance->music != nullptr) {
            _graphicInstance->music.reset();
        }
        if (_graphicInstance->texture != nullptr) {
            _graphicInstance->texture.reset();
        }
        _graphicInstance.reset();
    }

    create =
        reinterpret_cast<create_func_gfx>(_graphic.load_symbol("factory"));
    std::unique_ptr<IGfxController> controller = create();

    _graphicInstance = std::make_unique<GraphicsType_s>();
    _graphicInstance->controller = std::move(controller);
    //_graphicInstance->event = _graphicInstance->controller->createEvent();
    _graphicInstance->display = _graphicInstance->controller->createDisplay();
    _graphicInstance->music = _graphicInstance->controller->createMusic();
    _graphicInstance->texture = _graphicInstance->controller->createTexture();
}

void Arcade::Core::runGraphic()
{
    std::vector<std::string> grid = _gameInstance->getGameGrid();
    int gameStatus = 0;
    _graphicInstance->display->init_gfx(grid);
    while ((gameStatus = _gameInstance->update()) != 1
        && _graphicInstance->display->update(grid) == 0) {
        _graphicInstance->display->display_score(
            _gameInstance->getScore(), 10, 21);
        grid = _gameInstance->getGameGrid();
        switch (gameStatus) {
            case (PREV_GAME): prevGame(); break;
            case (NEXT_GAME): nextGame(); break;
            case (PREV_GRAPHIC): prevGraphic(); return;
            case (NEXT_GRAPHIC): nextGraphic(); return;
            default: break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        continue;
    }
}

void Arcade::Core::setUsername(const std::string &username)
{
    _username = username;
}

const std::string &Arcade::Core::getUsername() const
{
    return _username;
}

bool Arcade::Core::exitAll(void) const
{
    // exit all
    this->saveData();
    // this->_gameInstance->end();
    // this->_graphicInstance->display->end_gfx();
    // this->_graphicInstance->event->end_event();
    // this->_graphicInstance->music->end_music();
    // this->_graphicInstance->texture->end_texture();
    return true;
}

bool Arcade::Core::nextGame()
{
    this->_gameInstance->end();
    this->_gameInstance.reset();
    const std::string name = this->_game.getFilename();
    const std::vector<std::string> games = this->_parser.getGames();
    int size = static_cast<int>(games.size());
    for (int i = 0; i < size; i++) {
        if (games[i] == name) {
            if (i + 1 < size) {
                this->_game.changeLib(games[i + 1]);
                this->reloadGame();
                break;
            } else {
                this->_game.changeLib(games[0]);
                this->reloadGame();
                break;
            }
        }
    }
    return true;
}

bool Arcade::Core::prevGame()
{
    this->_gameInstance->end();
    this->_gameInstance.reset();
    const std::string name = this->_game.getFilename();
    const std::vector<std::string> games = this->_parser.getGames();
    int size = static_cast<int>(games.size());
    for (int i = 0; i < size; i++) {
        if (games[i] == name) {
            if (i - 1 >= 0) {
                this->_game.changeLib(games[i - 1]);
                break;
            } else {
                this->_game.changeLib(games[games.size() - 1]);
                break;
            }
        }
    }
    this->reloadGame();
    return true;
}

bool Arcade::Core::nextGraphic()
{
    std::cout << "Next graphic" << std::endl;
    // change graphic
    this->_graphicInstance.reset();
    const std::string name = this->_graphic.getFilename();
    const std::vector<std::string> graphics = this->_parser.getGraphics();
    bool isChange = false;
    int size = static_cast<int>(graphics.size());
    for (int i = 0; i < size; i++) {
        if (graphics[i] == name) {
            if (i + 1 < size) {
                this->_graphic.changeLib(graphics[i + 1]);
                isChange = true;
                break;
            } else {
                this->_graphic.changeLib(graphics[0]);
                isChange = true;
                break;
            }
        }
    }
    if (!isChange)
        return false;
    this->reloadGraphic();
    _gameInstance->start(_graphicInstance->controller);
    // run graphic
    this->runGraphic();
    return true;
}

bool Arcade::Core::prevGraphic()
{
    // end graphic

    // change graphic
    this->_graphicInstance.reset();
    const std::string name = this->_graphic.getFilename();
    const std::vector<std::string> graphics = this->_parser.getGraphics();
    int size = static_cast<int>(graphics.size());
    bool isChange = false;
    for (int i = 0; i < size; i++) {
        if (graphics[i] == name) {
            if (i - 1 >= 0) {
                this->_graphic.changeLib(graphics[i - 1]);
                isChange = true;
                break;
            } else {
                this->_graphic.changeLib(graphics[graphics.size() - 1]);
                isChange = true;
                break;
            }
        }
    }
    if (!isChange)
        return false;
    this->reloadGraphic();
    _gameInstance->start(_graphicInstance->controller);
    // run graphic
    this->runGraphic();
    return true;
}

bool Arcade::Core::saveData() const
{
    std::ofstream file;
    file.open(".arcade");
    file << this->_username;
    file.close();
    return true;
}

bool Arcade::Core::loadData()
{
    std::ifstream file;
    file.open(".arcade");
    if (file.is_open()) {
        std::getline(file, this->_username);
        file.close();
        return true;
    }
    this->_username = "Player";
    return false;
}
