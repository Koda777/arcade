/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** fruit
*/

#include "../include/Fruit.hpp"

Fruit::Fruit(FruitType fruitType, size_t y, size_t x)
{
    setFruitType(fruitType);
    setFruitPos(y, x);
}

void Fruit::setFruitPos(size_t y, size_t x)
{
    _fruitPos.y = y;
    _fruitPos.x = x;
}

size_t Fruit::getFruitPosX()
{
    return _fruitPos.x;
}

size_t Fruit::getFruitPosY()
{
    return _fruitPos.y;
}

Fruit::FruitType Fruit::getFruitType()
{
    return _fruitType;
}

void Fruit::setFruitType(Fruit::FruitType fruitType)
{
    _fruitType = fruitType;
}
