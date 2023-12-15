/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** fruit hpp
*/

#include <unistd.h>
#include "Snake.hpp"

#pragma once

class Fruit {
  public:
    enum FruitType {
        APPLE,
        BANANA,
        ORANGE,
        PEAR,
        PINEAPPLE,
        STRAWBERRY,
        WATERMELON
    };
    Fruit(FruitType fruitType = APPLE, size_t y = 5, size_t x = 5);
        ~Fruit(){};
    void setFruitPos(size_t y, size_t x);
    size_t getFruitPosX();
    size_t getFruitPosY();
    FruitType getFruitType();
    void setFruitType(FruitType fruitType);

  protected:
  private:
    Coordinate _fruitPos;
    FruitType _fruitType;
};
