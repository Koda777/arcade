/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** fruit hpp
*/

#include <unistd.h>
#include "Nibbler.hpp"

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
    Fruit(FruitType fruitType = APPLE);
    ~Fruit(){};
    void setFruitPos(size_t y, size_t x);
    size_t getFruitPosX() const;
    size_t getFruitPosY() const;
    Coordinate getFruitPos() const;
    FruitType getFruitType();
    void setFruitType(FruitType fruitType);
    void swap(Fruit& lhs, Fruit& rhs);

  protected:
  private:
    Coordinate _fruitPos;
    FruitType _fruitType;
};
