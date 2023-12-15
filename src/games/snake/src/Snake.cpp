/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake.cpp
*/

#include "../include/Snake.hpp"
#include "../../controller/include/IGame.hpp"

// GETTERS AND SETTERS

std::vector<Coordinate> Snake::getSnake() const
{
    return _snakePos;
}

Coordinate Snake::getHeadPosition() const
{
    return _snakePos[0];
}

Coordinate Snake::getXPosition(int x) const
{
    return _snakePos[x];
}

Coordinate Snake::getTailPosition() const
{
    return _snakePos[_snakePos.size() - 1];
}

Coordinate Snake::getNextPosition() const
{
    Coordinate nextPos;
    switch (getDirection()) {
        case UP:
            nextPos.x = getHeadPosition().x;
            nextPos.y = getHeadPosition().y - 1;
            break;
        case DOWN:
            nextPos.x = getHeadPosition().x;
            nextPos.y = getHeadPosition().y + 1;
            break;
        case LEFT:
            nextPos.x = getHeadPosition().x - 1;
            nextPos.y = getHeadPosition().y;
            break;
        case RIGHT:
            nextPos.x = getHeadPosition().x + 1;
            nextPos.y = getHeadPosition().y;
            break;
        default: break;
    }
    return nextPos;
}

Snake::Direction Snake::getDirection() const
{
    return _direction;
}

void Snake::setDirection(Direction direction)
{
    _direction = direction;
}

// MEMBER FUNCTIONS

void Snake::addSegment()
{
    Coordinate newSegment;
    switch (getDirection()) {
        case UP:
            newSegment.x = getTailPosition().x;
            newSegment.y = getTailPosition().y - 1;
            break;
        case DOWN:
            newSegment.x = getTailPosition().x;
            newSegment.y = getTailPosition().y + 1;
            break;
        case LEFT:
            newSegment.x = getTailPosition().x - 1;
            newSegment.y = getTailPosition().y;
            break;
        case RIGHT:
            newSegment.x = getTailPosition().x + 1;
            newSegment.y = getTailPosition().y;
            break;
        default: break;
    }
    _snakePos.push_back(newSegment);
}

int Snake::checkSelfCollision() const
{
    Coordinate nextPos;
    switch (getDirection()) {
        case UP:
            nextPos.x = getHeadPosition().x;
            nextPos.y = getHeadPosition().y - 1;
            break;
        case DOWN:
            nextPos.x = getHeadPosition().x;
            nextPos.y = getHeadPosition().y + 1;
            break;
        case LEFT:
            nextPos.x = getHeadPosition().x - 1;
            nextPos.y = getHeadPosition().y;
            break;
        case RIGHT:
            nextPos.x = getHeadPosition().x + 1;
            nextPos.y = getHeadPosition().y;
            break;
        default: break;
    }
    for (unsigned int i = 1; i < getSnake().size(); i++) {
        if (nextPos.x == getXPosition(i).x && nextPos.y == getXPosition(i).y)
            return 1;
    }
    return 0;
}

int Snake::checkCollision()
{
    Coordinate nextPos = getNextPosition();
    if (nextPos.x < 2 || nextPos.x > 19 || nextPos.y < 2 || nextPos.y > 19)
        return 1;
    if (checkSelfCollision())
        return 1;
    return 0;
}

void Snake::moveHead()
{
    switch (getDirection()) {
        case UP: _snakePos[0].y -= 1; break;
        case DOWN: _snakePos[0].y += 1; break;
        case LEFT: _snakePos[0].x -= 1; break;
        case RIGHT: _snakePos[0].x += 1; break;
        default: break;
    }
}

void Snake::moveSnake()
{
    for (int i = getSnake().size() - 1; i > 0; i--) {
        _snakePos[i].x = getXPosition(i - 1).x;
        _snakePos[i].y = getXPosition(i - 1).y;
    }
    moveHead();
}
