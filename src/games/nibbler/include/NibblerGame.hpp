/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** snakegamehpp
*/

#include <string>
#include "Fruit.hpp"
#include "Nibbler.hpp"

#pragma once

#include <unistd.h>

class NibblerGame : public Game {
  public:
    NibblerGame();
    NibblerGame(size_t x, size_t y);
    std::vector<Fruit> &getFruits();
    Fruit getFruitX(size_t x) const;
    void setFruitX(Fruit fruit, size_t x);
    Nibbler &getNibbler();
    Coordinate getFruitXPos(size_t x) const;
    Coordinate getNibblerHeadPos();
    Coordinate getNibblerXPos(size_t x);
    void setFruitXPos(size_t x, size_t y, size_t fruitRank);
    size_t getFruitCount() const;
    size_t getNibblerLength();
    void moveNibbler();
    void setFruitCount(size_t count);
    bool checkEatFruit();
    bool checkSelfCollision();
    bool checkWallCollision();
    bool checkCollision();
    void addWalls();
    void removeFruitX(size_t x);
    int update() override;
    void drawNibbler();
    int checkKeys();
    void clearNibbler();
    ~NibblerGame(){};

  protected:
  private:
    std::vector<Fruit> _fruits;
    Nibbler _snake;
    size_t _fruitCount = 26;
};

extern "C" std::unique_ptr<IGame> factory();
