/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** fruit
*/

#include "../include/Fruit.hpp"

Fruit::Fruit(FruitType fruitType)
{
    setFruitType(fruitType);
}

void Fruit::setFruitPos(size_t y, size_t x)
{
    _fruitPos.x = x;
    _fruitPos.y = y;
}

size_t Fruit::getFruitPosX() const
{
    return _fruitPos.x;
}

size_t Fruit::getFruitPosY() const
{
    return _fruitPos.y;
}

Coordinate Fruit::getFruitPos() const
{
    return _fruitPos;
}

Fruit::FruitType Fruit::getFruitType()
{
    return _fruitType;
}

void Fruit::setFruitType(Fruit::FruitType fruitType)
{
    _fruitType = fruitType;
}
