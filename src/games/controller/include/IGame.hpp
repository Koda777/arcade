/*
** EPITECH PROJECT, 2023
** Game
** File description:
** IGame.hpp
*/

#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <vector>
#include "../../../graphics/Gfx/Controller/include/IGfxController.hpp"

struct Coordinate {
  size_t y;
  size_t x;
};

inline bool checkCoordinateEqual(Coordinate pos1, Coordinate pos2) {
  return pos1.x == pos2.x && pos1.y == pos2.y;
}

class IGame {
public:
  IGame() = default;
  virtual ~IGame() = default;
  virtual int start(std::unique_ptr<IGfxController> &gfx) = 0;
  virtual std::vector<std::string> &getGameGrid() = 0;
  virtual int update() = 0;
  virtual size_t getScore() = 0;
  virtual int end() = 0;
};
