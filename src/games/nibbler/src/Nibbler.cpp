/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Nibbler.cpp
*/

#include "../include/Nibbler.hpp"
#include "../../controller/include/IGame.hpp"

Nibbler::Nibbler()
{
}

Nibbler::~Nibbler()
{
}

// GETTERS AND SETTERS

std::vector<Coordinate> Nibbler::getNibbler() const
{
    return _snakePos;
}

Coordinate Nibbler::getHeadPosition() const
{
    return _snakePos[0];
}

Coordinate Nibbler::getXPosition(int x) const
{
    return _snakePos[x];
}

Coordinate Nibbler::getTailPosition() const
{
    return _snakePos[_snakePos.size() - 1];
}

Coordinate Nibbler::getNextPosition() const
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

Nibbler::Direction Nibbler::getDirection() const
{
    return _direction;
}

void Nibbler::setDirection(Direction direction)
{
    _direction = direction;
}

// MEMBER FUNCTIONS

void Nibbler::addSegment()
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

int Nibbler::checkSelfCollision() const
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
    for (unsigned int i = 1; i < getNibbler().size(); i++) {
        if (nextPos.x == getXPosition(i).x && nextPos.y == getXPosition(i).y)
            return 1;
    }
    return 0;
}

void Nibbler::moveHead()
{
    switch (getDirection()) {
        case UP: _snakePos[0].y -= 1; break;
        case DOWN: _snakePos[0].y += 1; break;
        case LEFT: _snakePos[0].x -= 1; break;
        case RIGHT: _snakePos[0].x += 1; break;
        default: break;
    }
}

void Nibbler::moveNibbler()
{
    for (int i = getNibbler().size() - 1; i > 0; i--) {
        _snakePos[i].x = getXPosition(i - 1).x;
        _snakePos[i].y = getXPosition(i - 1).y;
    }
    moveHead();
}

size_t Nibbler::getLength() const
{
    return _snakePos.size();
}
