/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Display.hpp
*/


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include "../../../Gfx/Display/include/Display.hpp"

class SDLDisplay : public Display{
public:
    SDLDisplay();
    ~SDLDisplay();

    void init_gfx(std::vector<std::string> &gameGrid);
    void display_score(int score, int pos_x, int pos_y);
    int update(std::vector<std::string> &gameGrid);
    void micro_sleep(int sleep);
    void display_end(int seconds, int score, int maxx, int maxy);
    void close_window();
    void display_chara(int x, int y, char chara);
    void clear_window();

private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;
    TTF_Font *font_;
    std::vector<SDL_Texture*> texts_;
};