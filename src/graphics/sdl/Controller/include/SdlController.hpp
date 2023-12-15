/*
** EPITECH PROJECT, 2023
** graphics
** File description:
** GfxSDL.hpp
*/

#pragma once
#include <memory>
#include "../../../Gfx/Controller/include/IGfxController.hpp"
#include "../../Display/include/SdlDisplay.hpp"
#include "../../Event/include/SdlEvent.hpp"
#include "../../Music/include/SdlMusic.hpp"
#include "../../Texture/include/SdlTexture.hpp"
#include "IDisplay.hpp"

class SDLController : public IGfxController {
  public:
    SDLController() = default;
    ~SDLController() = default;
    std::unique_ptr<IDisplay> createDisplay(void) override
    {
        return std::make_unique<SDLDisplay>();
    };
    std::unique_ptr<IMusic> createMusic() override
    {
        return std::make_unique<SDLMusic>();
    };
    std::unique_ptr<IEvent>createEvent() override
    {
        return std::make_unique<SDLEvent>();
    }
    std::unique_ptr<ITexture>createTexture() override
    {
        return std::make_unique<SDLTexture>();
    };

  protected:
  private:
};

extern "C" std::unique_ptr<IGfxController> factory(void);
