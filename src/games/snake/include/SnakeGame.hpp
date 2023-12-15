/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** snakegamehpp
*/

#include "Fruit.hpp"
#include "Snake.hpp"

#pragma once

#include <unistd.h>

class SnakeGame : public Game {
public:
  enum FruitChar {
    APPLE = 'A',
    BANANA = 'B',
    ORANGE = 'N',
    PEAR = 'P',
    PINEAPPLE = 'I',
    STRAWBERRY = 'S',
    WATERMELON = 'W'
  };
  SnakeGame();
  Fruit &getFruit();
  void setFruit(Fruit fruit);
  Snake& getSnake();
  Coordinate getFruitPos();
  Coordinate getSnakePosX(int x);
  Coordinate getSnakeHeadPos();
  Coordinate getValidFruitPos();
  size_t getSnakeLength();
  void setFruitPos(size_t y, size_t x);
  bool checkEatFruit();
  bool checkCollision();
  void removeFruit();
  void moveSnake();
  void drawFruit();
  void growSnake();
  void drawSnake();
  void clearSnake();
  int checkKeys();
  int update() override;
  ~SnakeGame(){};

protected:
private:
  Fruit _fruit;
  Snake _snake;
};

extern "C" std::unique_ptr<IGame> factory();
