/*
** EPITECH PROJECT, 2023
** graphics
** File description:
** Display.hpp
*/
#pragma once
#include "IDisplay.hpp"
#include <iostream>

class Display : public IDisplay {
public:
  Display() { std::cout << "Display created" << std::endl; };
  ~Display(){};

  void init_gfx(std::vector<std::string> &gameGrid);
  void display_score(int score, int pos_x, int pos_y);
  int update(std::vector<std::string> &gameGrid);
  void micro_sleep(int sleep);
  void display_end(int seconds, int score, int maxx, int maxy);
  void close_window(void);
  void display_chara(int x, int y, char chara);
  void clear_window();
};
