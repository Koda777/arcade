/*
** EPITECH PROJECT, 2023
** Game
** File description:
** Game.hpp
*/

#include <memory>
#include <string>
#include <vector>
#include "../../../graphics/Gfx/Event/include/Event.hpp"
#include "IGame.hpp"

class Game : public IGame {
  public:
    Game();
    ~Game();
    int update();
    size_t getScore();
    std::unique_ptr<IEvent> &getEvent()
    {
        return _event;
    }
    void setScore(size_t score);
    void setGameGrid(size_t x, size_t y);
    std::vector<std::string> &getGameGrid();
    size_t getGameGridSizeX() const;
    size_t getGameGridSizeY() const;
    void setGameGgridSizeX(size_t x);
    void setGameGridSizeY(size_t y);
    int end()
    {
        return 0;
    };
    int start(std::unique_ptr<IGfxController> &gfx);

  private:
    size_t _score = 0;
    std::vector<std::string> _gameGrid;
    size_t _x = 20;
    size_t _y = 20;
    std::unique_ptr<IEvent> _event;
};

extern "C" std::unique_ptr<IGame> factory();
