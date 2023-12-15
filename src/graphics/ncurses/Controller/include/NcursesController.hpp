/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** .
*/
#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <ncurses.h>
#include <string>
#include "../../../Gfx/Controller/include/GfxController.hpp"
#include "../../Display/include/NcursesDisplay.hpp"
#include "../../Event/include/NcursesEvent.hpp"
#include "../../Music/include/NcursesMusic.hpp"
#include "../../Texture/include/NcursesTexture.hpp"

class NcursesController : public GfxController {
  public:
    ~NcursesController()
    {
        std::cout << "bye " << std::endl;
    };
    NcursesController()
    {
        std::cout << "Ncurses controller .." << std::endl;
    };
    std::unique_ptr<IDisplay> createDisplay(void) override
    {
        return std::make_unique<NcursesDisplay>();
    };
    std::unique_ptr<IMusic> createMusic() override
    {
        return std::make_unique<NcursesMusic>();
    };
    std::unique_ptr<IEvent> createEvent() override
    {
        return std::make_unique<NcursesEvent>();
    }
    std::unique_ptr<ITexture> createTexture() override
    {
        return std::make_unique<NcursesTexture>();
    };
};

extern "C" std::unique_ptr<IGfxController> factory();
