/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** snake game
*/

#include "../include/NibblerGame.hpp"
#include <cstddef>
#include <memory>
#include "../../controller/include/IGame.hpp"

NibblerGame::NibblerGame() : _fruits(26)
{
    setGameGrid(getGameGridSizeX(), getGameGridSizeY());
    for (size_t i = 0; i < getGameGridSizeX(); i++) {
        getGameGrid()[0][i] = '#';
        getGameGrid()[getGameGridSizeY() - 1][i] = '#';
    }
    for (size_t i = 1; i < getGameGridSizeY() - 2; i++) {
        getGameGrid()[i][0] = '#';
        for (size_t j = 1; j < getGameGridSizeX() - 2; j++)
            getGameGrid()[i][j] = ' ';
        getGameGrid()[i][getGameGridSizeX() - 1] = '#';
    }
    addWalls();
    drawNibbler();
}

NibblerGame::NibblerGame(size_t x, size_t y)
{
    setGameGrid(x, y);
    setGameGgridSizeX(x);
    setGameGridSizeY(y);
}

std::vector<Fruit> &NibblerGame::getFruits()
{
    return _fruits;
}

Fruit NibblerGame::getFruitX(size_t x) const
{
    return _fruits[x];
}

Coordinate NibblerGame::getFruitXPos(size_t x) const
{
    Coordinate fruitPos;

    fruitPos.x = getFruitX(x).getFruitPosX();
    fruitPos.y = getFruitX(x).getFruitPosY();
    return fruitPos;
}

void NibblerGame::setFruitXPos(size_t x, size_t y, size_t fruitRank)
{
    getFruitX(fruitRank).setFruitPos(x, y);
}

void NibblerGame::setFruitX(Fruit fruit, size_t x)
{
    _fruits[x] = fruit;
}

Nibbler &NibblerGame::getNibbler()
{
    return _snake;
}

Coordinate NibblerGame::getNibblerHeadPos()
{
    return getNibbler().getHeadPosition();
}

void NibblerGame::removeFruitX(size_t x)
{
    getFruits().erase(getFruits().begin() + x);
    setFruitCount(getFruitCount() - 1);
}

bool NibblerGame::checkEatFruit()
{
    size_t maxSize = getFruits().size();
    Coordinate nextPos = getNibbler().getNextPosition();
    for (size_t i = 0; i < maxSize; i++) {
        if (getGameGrid()[nextPos.y][nextPos.x] == 'A') {
            removeFruitX(i);
            setScore(getScore() + 10);
            getNibbler().addSegment();
            setFruitCount(getFruitCount() - 1);
            return true;
        }
    }
    return false;
}

bool NibblerGame::checkWallCollision()
{
    if (getGameGrid()[getNibbler().getNextPosition().y]
                     [getNibbler().getNextPosition().x]
        == '#')
        return true;
    return false;
}

bool NibblerGame::checkSelfCollision()
{
    return getNibbler().checkSelfCollision();
}

bool NibblerGame::checkCollision()
{
    if (checkWallCollision() || checkSelfCollision())
        return true;
    return false;
}

void NibblerGame::addWalls()
{
    getGameGrid()[0] = "####################";
    getGameGrid()[1] = "#                  #";
    getGameGrid()[2] = "#  A   A    A   A  #";
    getGameGrid()[3] = "# ### # #### # ### #";
    getGameGrid()[4] = "#A# #A#      #A# #A#";
    getGameGrid()[5] = "# ### # #  # # ### #";
    getGameGrid()[6] = "#     #A#  #A#     #";
    getGameGrid()[7] = "# ##### #  # ##### #";
    getGameGrid()[8] = "# # A          A # #";
    getGameGrid()[9] = "# # #####  ##### # #";
    getGameGrid()[10] = "# A     A  A     A #";
    getGameGrid()[11] = "# ##### #### ##### #";
    getGameGrid()[12] = "#  A    #  #    A  #";
    getGameGrid()[13] = "# ### # #### # ### #";
    getGameGrid()[14] = "#A# #A#      #A# #A#";
    getGameGrid()[15] = "# ### # #### # ### #";
    getGameGrid()[16] = "#     # #  # #     #";
    getGameGrid()[17] = "# ##### #### ##### #";
    getGameGrid()[18] = "#  A   A    A   A  #";
    getGameGrid()[19] = "####################";
}

size_t NibblerGame::getFruitCount() const
{
    return _fruitCount;
}

size_t NibblerGame::getNibblerLength()
{
    return getNibbler().getLength();
}

void NibblerGame::moveNibbler()
{
    getNibbler().moveNibbler();
}

void NibblerGame::setFruitCount(size_t count)
{
    _fruitCount = count;
}

std::unique_ptr<IGame> factory()
{
    return std::make_unique<NibblerGame>();
}

Coordinate NibblerGame::getNibblerXPos(size_t x)
{
    return getNibbler().getXPosition(x);
}

void NibblerGame::clearNibbler()
{
    for (size_t i = 0; i < getNibblerLength(); i++)
        getGameGrid()[getNibblerXPos(i).y][getNibblerXPos(i).x] = ' ';
}

void NibblerGame::drawNibbler()
{
    for (size_t i = 0; i < getNibblerLength(); i++)
        getGameGrid()[getNibblerXPos(i).y][getNibblerXPos(i).x] = 'Q';
}

int NibblerGame::checkKeys()
{
    KEY key = getEvent()->control_key();
    switch (key) {
        case KEY::UP:
            getNibbler().setDirection(Nibbler::UP);
            return 0;
            ;
        case KEY::DOWN:
            getNibbler().setDirection(Nibbler::DOWN);
            return 0;
            ;
        case KEY::LEFT:
            getNibbler().setDirection(Nibbler::LEFT);
            return 0;
            ;
        case KEY::RIGHT: getNibbler().setDirection(Nibbler::RIGHT); break;
        case KEY::NEXT_GAME: return NEXT_GAME;
        case KEY::PREV_GAME: return PREV_GAME;
        case KEY::NEXT_GRAPHIC: return NEXT_GRAPHIC;
        case KEY::PREV_GRAPHIC: return PREV_GRAPHIC;
        case KEY::EXIT: return 1;
        default: return 0; ;
    }
    return 0;
}

int NibblerGame::update()
{
    int returnKey;

    clearNibbler();
    if (checkSelfCollision())
        return 1;
    checkEatFruit();
    if (!checkWallCollision())
        moveNibbler();
    returnKey = checkKeys();
    drawNibbler();
    return returnKey;
}
