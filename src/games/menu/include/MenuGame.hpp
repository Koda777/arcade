/*
** EPITECH PROJECT, 2023
** include
** File description:
** menu.hpp
*/
#pragma once
#include "../../controller/include/Game.hpp"
#include "Parser.hpp"
#include <initializer_list>
#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef struct scene_t {
  std::vector<std::string> args;

  scene_t(std::initializer_list<std::string> initList) : args(initList) {}
} scene_s;

typedef struct items_t {
  std::string name;
  size_t y;
} items_s;

class MenuGame : public Game, Parser {
public:
  MenuGame();
  ~MenuGame();
  void initGameMenu(void);

private:
  std::map<std::string, std::string> gameMenu_;
  std::map<size_t, items_s> menuSelected_;
  std::string currentScene_;
  size_t cursorY_;
  void fillWord(const std::string word, size_t x, size_t y);
  std::map<std::string, const scene_s> scene_;
  std::vector<std::string> gameList_;
  int update() override;
  void initMenu();
  void fillMenu();
  void initScene();
};
