/*
** EPITECH PROJECT, 2023
** graphics
** File description:
** NcursesEvent.hpp
*/

#pragma once
#include "../../../Gfx/Event/include/Event.hpp"
#include <ncurses.h>

class NcursesEvent : public Event {
  public:
    NcursesEvent(){};
    ~NcursesEvent(){};
    KEY control_key();
};
