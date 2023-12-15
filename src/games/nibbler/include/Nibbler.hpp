/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Nibbler.hpp
*/

#pragma once

#include <vector>
#include "../../controller/include/Game.hpp"

class Nibbler {
  public:
    enum Direction { UP, DOWN, LEFT, RIGHT };
    Nibbler();
    ~Nibbler();
    void addSegment();
    std::vector<Coordinate> getNibbler() const;
    Coordinate getHeadPosition() const;
    Coordinate getXPosition(int x) const;
    Coordinate getTailPosition() const;
    Coordinate getNextPosition() const;
    Direction getDirection() const;
    void setDirection(Direction direction);
    int checkSelfCollision() const;
    void moveHead();
    void moveNibbler();
    size_t getLength() const;

  protected:
  private:
    std::vector<Coordinate> _snakePos = {{1, 10}, {1, 9}, {1, 8}};
    Direction _direction = RIGHT;
};
