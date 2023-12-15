/*
** EPITECH PROJECT, 2023
** graphics
** File description:
** GfxSFML.hpp
*/

#pragma once
#include <SFML/Window/Window.hpp>
#include <memory>
#include "../../../Gfx/Controller/include/IGfxController.hpp"
#include "../../Display/include/SfmlDisplay.hpp"
#include "../../Event/include/SfmlEvent.hpp"
#include "../../Music/include/SfmlMusic.hpp"
#include "../../Texture/include/SfmlTexture.hpp"

class SFMLController : public IGfxController {
  public:
    SFMLController() = default;
    ~SFMLController() = default;
    std::unique_ptr<IDisplay> createDisplay(void) override
    {
        return std::make_unique<SFMLDisplay>();
    };
    std::unique_ptr<IMusic> createMusic() override
    {
        return std::make_unique<SFMLMusic>();
    };
    std::unique_ptr<IEvent> createEvent() override
    {
        return std::make_unique<SFMLEvent> ();
    }
    std::unique_ptr<ITexture> createTexture() override
    {
        return std::make_unique<SFMLTexture>();
    };

  protected:
  private:
};

extern "C" std::unique_ptr<IGfxController> factory();
