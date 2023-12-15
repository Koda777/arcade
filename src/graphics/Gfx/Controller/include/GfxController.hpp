/*
** EPITECH PROJECT, 2023
** GfxController
** File description:
** IGfxController.hpp
*/
#pragma once
#include <memory>
#include "../../Display/include/Display.hpp"
#include "../../Event/include/Event.hpp"
#include "../../Music/include/Music.hpp"
#include "../../Texture/include/Texture.hpp"
#include "IGfxController.hpp"

class GfxController : public IGfxController {
  public:
    GfxController() = default;
    ~GfxController() = default;
    std::unique_ptr<IDisplay> createDisplay(void)
    {
        return std::make_unique<Display>();
    };
    std::unique_ptr<IMusic> createMusic()
    {
        return std::make_unique<Music>();
    };
    std::unique_ptr<IEvent> createEvent()
    {
        return std::make_unique<Event>();
    };
    std::unique_ptr<ITexture> createTexture()
    {
        return std::make_unique<Texture>();
    };
};
