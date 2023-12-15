// source file for SdlEvent

#include "../include/SdlEvent.hpp"
#include <SDL2/SDL.h>
#include "IEvent.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>

KEY SDLEvent::control_key()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN)
            std::cout << event.key.keysym.sym << std::endl;
        switch (event.type) {
            case SDL_QUIT:
                return EXIT;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        return UP;
                    case SDLK_DOWN:
                        return DOWN;
                    case SDLK_LEFT:
                        return LEFT;
                    case SDLK_RIGHT:
                        return RIGHT;
                    case SDLK_ESCAPE:
                        return EXIT;
                    case SDLK_n:
                        return PREV_GAME;
                    case SDLK_m:
                        return NEXT_GAME;
                    case SDLK_j:
                        return PREV_GRAPHIC;
                    case SDLK_k:
                        return NEXT_GRAPHIC;
                    default:
                        return NONE;
                }
            default:
                return NONE;
        }
    }
    return NONE;
}