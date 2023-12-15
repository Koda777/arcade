/*
** EPITECH PROJECT, 2023
** gfx
** File description:
** IDisplay.hpp
*/
#pragma once
#include <string>
#include <vector>

class IDisplay {
public:
  virtual ~IDisplay() = default;
  virtual void init_gfx(std::vector<std::string> &gameGrid) = 0;
  virtual void display_score(int score, int pos_x, int pos_y) = 0;
  virtual int update(std::vector<std::string> &gameGrid) = 0;
  virtual void micro_sleep(int sleep) = 0;
  virtual void display_end(int seconds, int score, int maxx, int maxy) = 0;
  virtual void close_window(void) = 0;
  virtual void display_chara(int x, int y, char chara) = 0;
  virtual void clear_window() = 0;

protected:
private:
};
