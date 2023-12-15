/*
** EPITECH PROJECT, 2023
** Gfx
** File description:
** Event.hpp
*/

#pragma once
#include <iostream>
#include <string>
#include "IEvent.hpp"

class Event : public IEvent {
  public:
    Event()
    {
        std::cout << "Event created" << std::endl;
    }
    ~Event() {};
    KEY control_key(void);
};
