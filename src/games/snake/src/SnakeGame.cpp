/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** snake game
*/

#include "../include/SnakeGame.hpp"
#include <cstdlib>
#include <ctime>

SnakeGame::SnakeGame()
{
    setGameGrid(getGameGridSizeX(), getGameGridSizeY());
    for (size_t i = 0; i < getGameGridSizeX(); i++) {
        getGameGrid()[0][i] = '#';
        getGameGrid()[getGameGridSizeY() - 1][i] = '#';
    }
    for (size_t i = 1; i < getGameGridSizeY() - 1; i++) {
        getGameGrid()[i][0] = '#';
        for (size_t j = 1; j < getGameGridSizeX() - 1; j++)
            getGameGrid()[i][j] = ' ';
        getGameGrid()[i][getGameGridSizeX() - 1] = '#';
    }
    setFruit(Fruit(Fruit::FruitType(rand() % 6)));
    setFruitPos(getValidFruitPos().y, getValidFruitPos().x);
    drawSnake();
    drawFruit();
}

Fruit &SnakeGame::getFruit()
{
    return _fruit;
}

Coordinate SnakeGame::getFruitPos()
{
    Coordinate fruitPos;

    fruitPos.x = getFruit().getFruitPosX();
    fruitPos.y = getFruit().getFruitPosY();
    return fruitPos;
}

void SnakeGame::setFruitPos(size_t y, size_t x)
{
    getFruit().setFruitPos(y, x);
}

void SnakeGame::setFruit(Fruit fruit)
{
    _fruit = fruit;
}

Snake &SnakeGame::getSnake()
{
    return _snake;
}

Coordinate SnakeGame::getSnakeHeadPos()
{
    return getSnake().getHeadPosition();
}

Coordinate SnakeGame::getSnakePosX(int x)
{
    return getSnake().getXPosition(x);
}

size_t SnakeGame::getSnakeLength()
{
    return getSnake().getSnake().size();
}

Coordinate SnakeGame::getValidFruitPos()
{
    bool status = false;
    size_t posx;
    size_t posy;
    srand(time(nullptr));
    while (!status) {
        posy = std::rand() % 16 + 2;
        posx = std::rand() % 16 + 2;
        for (size_t i = 0; i < getSnake().getSnake().size(); i++) {
            if (!checkCoordinateEqual(getSnakePosX(i), {posy, posx}))
                status = true;
        }
    }
    return {posy, posx};
}

bool SnakeGame::checkEatFruit()
{
    srand(time(nullptr));
    if (checkCoordinateEqual(getSnake().getNextPosition(), getFruitPos())) {
        Fruit newFruit;
        removeFruit();
        newFruit.setFruitType(Fruit::FruitType(rand() % 6));
        newFruit.setFruitPos(getValidFruitPos().x, getValidFruitPos().y);
        setFruit(newFruit);
        drawFruit();
        setScore(getScore() + 50);
        getSnake().addSegment();
        return true;
    }
    return false;
}

bool SnakeGame::checkCollision()
{
    return (getSnake().checkSelfCollision()
        || getGameGrid()[getSnake().getNextPosition().y]
                        [getSnake().getNextPosition().x]
            == '#');
}

void SnakeGame::moveSnake()
{
    getSnake().moveSnake();
}

void SnakeGame::drawFruit()
{
    getGameGrid()[getFruitPos().y][getFruitPos().x] =
        FruitChar(getFruit().getFruitType());
}

void SnakeGame::removeFruit()
{
    getGameGrid()[getFruitPos().y][getFruitPos().x] = ' ';
}

std::unique_ptr<IGame> factory()
{
    return std::make_unique<SnakeGame>();
}

void SnakeGame::growSnake()
{
    getSnake().addSegment();
}

void SnakeGame::clearSnake()
{
    for (size_t i = 0; i < getSnakeLength(); i++)
        getGameGrid()[getSnakePosX(i).y][getSnakePosX(i).x] = ' ';
}

void SnakeGame::drawSnake()
{
    for (size_t i = 0; i < getSnakeLength(); i++)
        getGameGrid()[getSnakePosX(i).y][getSnakePosX(i).x] = 'Q';
}

int SnakeGame::checkKeys()
{
    Snake::Direction activeDir = getSnake().getDirection();
    KEY key = getEvent()->control_key();
    switch (key) {
        case KEY::UP:
            getSnake().setDirection(
                activeDir == Snake::DOWN ? Snake::DOWN : Snake::UP);
            return 0;
        case KEY::DOWN:
            getSnake().setDirection(
                activeDir == Snake::UP ? Snake::UP : Snake::DOWN);
            return 0;
        case KEY::LEFT:
            getSnake().setDirection(
                activeDir == Snake::RIGHT ? Snake::RIGHT : Snake::LEFT);
            return 0;
        case KEY::RIGHT:
            getSnake().setDirection(
                activeDir == Snake::LEFT ? Snake::LEFT : Snake::RIGHT);
            return 0;
        case KEY::NEXT_GAME: return NEXT_GAME;
        case KEY::PREV_GAME: return PREV_GAME;
        case KEY::NEXT_GRAPHIC: return NEXT_GRAPHIC;
        case KEY::PREV_GRAPHIC: return PREV_GRAPHIC;
        default: return 0;
    }
}

int SnakeGame::update()
{
    int gameStatus = 0;
    clearSnake();
    if (checkCollision())
        return 1;
    moveSnake();
    gameStatus = checkKeys();
    drawSnake();
    checkEatFruit();
    return gameStatus;
}
