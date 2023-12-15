/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Game
*/

#include "../include/Game.hpp"
#include <iostream>

Game::Game()
{
    std::cout << "Game init" << std::endl;
}

Game::~Game()
{
}

std::vector<std::string> &Game::getGameGrid()
{
    return _gameGrid;
}

size_t Game::getGameGridSizeX() const
{
    return _x;
}

size_t Game::getGameGridSizeY() const
{
    return _y;
}

void Game::setGameGgridSizeX(size_t x)
{
    _x = x;
}

void Game::setGameGridSizeY(size_t y)
{
    _y = y;
}

void Game::setGameGrid(size_t x, size_t y)
{
    _gameGrid.resize(x);
    for (size_t i = 0; i < x; i++) {
        _gameGrid[i].resize(y);
    }
}

int Game::update()
{
    return 0;
}

size_t Game::getScore()
{
    return this->_score;
}

void Game::setScore(size_t score)
{
    this->_score = score;
}

int Game::start(std::unique_ptr<IGfxController> &gfx)
{
    std::unique_ptr<IEvent> event = gfx->createEvent();
    if (!event)
        return -1;
    _event = std::move(event);
    return 0;
}