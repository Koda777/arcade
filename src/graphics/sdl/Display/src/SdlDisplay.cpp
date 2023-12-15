/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Display.hpp
*/

#include "../include/SdlDisplay.hpp"
#include <iostream>
#include <ostream>

SDLDisplay::SDLDisplay()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    window_ = SDL_CreateWindow("My Game", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    renderer_ = SDL_CreateRenderer(
        window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    font_ = TTF_OpenFont("assets/Font.ttf", 24);
    if (!font_) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
}

SDLDisplay::~SDLDisplay()
{
    TTF_CloseFont(font_);
    TTF_Quit();
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

void SDLDisplay::init_gfx(std::vector<std::string> &gameGrid)
{
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect dstrect;
    SDL_Color color = {255, 255, 255, 255};

    for (size_t i = 0; i < gameGrid.size(); i++) {
        surface = TTF_RenderText_Solid(font_, gameGrid[i].c_str(), color);
        texture = SDL_CreateTextureFromSurface(renderer_, surface);
        dstrect.x = 50;
        dstrect.y = i * 24 + 50;
        dstrect.w = surface->w;
        dstrect.h = surface->h;
        texts_.push_back(texture);
        SDL_FreeSurface(surface);
    }
}

void SDLDisplay::display_score(int score, int pos_x, int pos_y)
{
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect dstrect;
    SDL_Color color = {255, 255, 255, 255};

    std::string text = "Score: " + std::to_string(score);
    surface = TTF_RenderText_Solid(font_, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer_, surface);
    dstrect.x = 0;
    dstrect.y = 25;
    dstrect.w = surface->w;
    dstrect.h = surface->h;
    texts_.push_back(texture);
    SDL_FreeSurface(surface);
}

int SDLDisplay::update(std::vector<std::string> &gameGrid)
{
    SDL_Color white = {255, 255, 255, 255};
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);
    for (size_t i = 0; i < gameGrid.size(); i++) {
        SDL_Surface *surface =
            TTF_RenderText_Solid(font_, gameGrid[i].c_str(), white);
        SDL_Texture *texture =
            SDL_CreateTextureFromSurface(renderer_, surface);
        SDL_Rect text_rect = {50, (int) (i * 24 + 50), surface->w, surface->h};
        SDL_RenderCopy(renderer_, texture, NULL, &text_rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
    SDL_RenderPresent(renderer_);
    return 0;
}

void SDLDisplay::micro_sleep(int sleep)
{
    SDL_Delay(sleep);
}

void SDLDisplay::display_end(int seconds, int score, int maxx, int maxy)
{
    SDL_Rect rect = {maxx / 2 - 150, maxy / 2 - 50, 0, 0};
    SDL_Surface *text_surface =
        TTF_RenderText_Solid(font_, "Game Over!", {255, 0, 0, 255});
    SDL_Texture *text_texture =
        SDL_CreateTextureFromSurface(renderer_, text_surface);
    SDL_FreeSurface(text_surface);
    SDL_Rect dstrect;
    SDL_QueryTexture(text_texture, nullptr, nullptr, &dstrect.w, &dstrect.h);
    dstrect.x = rect.x;
    dstrect.y = rect.y;
    SDL_RenderCopy(renderer_, text_texture, nullptr, &dstrect);

    char score_text[256];
    snprintf(score_text, 256, "Score: %d", score);
    text_surface =
        TTF_RenderText_Solid(font_, score_text, {255, 255, 255, 255});
    text_texture = SDL_CreateTextureFromSurface(renderer_, text_surface);
    SDL_FreeSurface(text_surface);
    SDL_QueryTexture(text_texture, nullptr, nullptr, &dstrect.w, &dstrect.h);
    dstrect.x = maxx / 2 - 50;
    dstrect.y = maxy / 2 + 50;
    SDL_RenderCopy(renderer_, text_texture, nullptr, &dstrect);

    char time_text[256];
    snprintf(time_text, 256, "Time: %d seconds", seconds);
    text_surface =
        TTF_RenderText_Solid(font_, time_text, {255, 255, 255, 255});
    text_texture = SDL_CreateTextureFromSurface(renderer_, text_surface);
    SDL_FreeSurface(text_surface);
    SDL_QueryTexture(text_texture, nullptr, nullptr, &dstrect.w, &dstrect.h);
    dstrect.x = maxx / 2 - 75;
    dstrect.y = maxy / 2 + 100;
    SDL_RenderCopy(renderer_, text_texture, nullptr, &dstrect);

    SDL_RenderPresent(renderer_);
    SDL_Delay(5000);
}

void SDLDisplay::close_window()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    TTF_Quit();
    SDL_Quit();
}

void SDLDisplay::display_chara(int x, int y, char chara)
{
    char chara_str[2] = {chara, '\0'};
    SDL_Surface *text_surface =
        TTF_RenderText_Solid(font_, chara_str, {255, 255, 255, 255});
    SDL_Texture *text_texture =
        SDL_CreateTextureFromSurface(renderer_, text_surface);
    SDL_FreeSurface(text_surface);
    SDL_Rect dstrect = {x, y, 0, 0};
    SDL_QueryTexture(text_texture, nullptr, nullptr, &dstrect.w, &dstrect.h);
    SDL_RenderCopy(renderer_, text_texture, nullptr, &dstrect);
    SDL_DestroyTexture(text_texture);
}

void SDLDisplay::clear_window()
{
    SDL_RenderClear(renderer_);
}
