/*
** EPITECH PROJECT, 2023
** GfxController
** File description:
** IGfxController.hpp
*/

#pragma once
#include <memory>
#include "../../Display/include/IDisplay.hpp"
#include "../../Event/include/IEvent.hpp"
#include "../../Music/include/IMusic.hpp"
#include "../../Texture/include/ITexture.hpp"

class IGfxController {
  public:
    virtual ~IGfxController() = default;
    virtual std::unique_ptr<IDisplay> createDisplay() = 0;
    virtual std::unique_ptr<IMusic> createMusic() = 0;
    virtual std::unique_ptr<IEvent> createEvent() = 0;
    virtual std::unique_ptr<ITexture> createTexture() = 0;
};
