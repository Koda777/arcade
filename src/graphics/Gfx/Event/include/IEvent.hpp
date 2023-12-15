/*
** EPITECH PROJECT, 2023
** Gfx
** File description:
** IEvent.hpp
*/

#pragma once
#include <iostream>
#include <string>

enum KEY { UP = 259, DOWN = 258, LEFT = 260, RIGHT = 261, EXIT = 2, ENTER, NEXT_GAME = 110, PREV_GAME = 109, NEXT_GRAPHIC = 107, PREV_GRAPHIC = 106, NONE = 0 };

class IEvent {
public:
  virtual ~IEvent() = default;
  virtual KEY control_key(void) = 0;

protected:
private:
};
