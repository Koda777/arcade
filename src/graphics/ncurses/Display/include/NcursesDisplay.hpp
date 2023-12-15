/*
** EPITECH PROJECT, 2023
** graphics
** File description:
** ncurses display
*/
#pragma once

#include <iostream>
#include <memory>
#include <ncurses.h>
#include "../../../Gfx/Display/include/Display.hpp"

class NcursesDisplay : public Display {
  public:
    NcursesDisplay();
    ~NcursesDisplay();
    void init_gfx(std::vector<std::string> &gameGrid) override;
    void display_score(int score, int pos_x, int pos_y) override;
    int update(std::vector<std::string> &gameGrid) override;
    void micro_sleep(int sleep) override;
    void display_end(int seconds, int score, int maxx, int maxy) override;
    void close_window(void) override;
    void display_chara(int x, int y, char chara) override;
    void clear_window() override;

  private:
    std::unique_ptr<WINDOW, decltype(&delwin)> win_;
};
