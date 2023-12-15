/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake.hpp
*/

#pragma once

#include "../../controller/include/Game.hpp"
#include <vector>

class Snake {

public:
  enum Direction { UP, DOWN, LEFT, RIGHT };
  Snake(){};
  ~Snake(){};
  void addSegment();
  std::vector<Coordinate> getSnake() const;
  Coordinate getHeadPosition() const;
  Coordinate getXPosition(int x) const;
  Coordinate getTailPosition() const;
  Coordinate getNextPosition() const;
  Direction getDirection() const;
  void setDirection(Direction direction);
  int checkSelfCollision() const;
  void moveHead();
  void moveSnake();
  int checkCollision();

protected:
private:
  std::vector<Coordinate> _snakePos = {{5, 10}, {4, 10}, {3, 10}};
  Direction _direction = DOWN;
};
