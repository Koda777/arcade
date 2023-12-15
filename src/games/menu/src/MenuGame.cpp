/*
** EPITECH PROJECT, 2023
** arcade
** File description:
**
*/

#include "../include/MenuGame.hpp"

static const scene_s scene_1 = {
    {"GAME"}, {"USER NAME => "}, {"START"}, {"EXIT"}};

static const std::map<std::string, std::string> gameMenu = {
    {"./lib/arcade_nibbler.so", "NIBBLER"},
    {"./lib/arcade_pacman.so", "PACMAN"},
    {"./lib/arcade_qix.so", "QIX"},
    {"./lib/arcade_centipede.so", "CENTIPEDE"},
    {"./lib/arcade_solarfox.so", "SOLARFOX"},
    {"./lib/arcade_snake.so", "SNAKE"}};

static const std::map<std::string, std::string> config = {{"fillWord", " "},
                                                          {"cursor", "> "}};

void MenuGame::initGameMenu(void) {
  auto currentGame = getGames();

  for (auto &game : currentGame) {
    auto it = gameMenu.find(game);
    if (it != gameMenu.end())
      gameList_.push_back(it->second);
  }
}

MenuGame::MenuGame() : Parser("./lib") {
  currentScene_ = "1";
  initMenu();
  initScene();
  fillMenu();
}

MenuGame::~MenuGame(void) {}

void MenuGame::initMenu(void) {
  setGameGrid(getGameGridSizeX(), getGameGridSizeY());
  const char fillWord = config.find("fillWord")->second[0];

  for (size_t i = 0; i < getGameGridSizeX(); i++) {
    getGameGrid()[0][i] = fillWord;
    getGameGrid()[getGameGridSizeY() - 1][i] = fillWord;
  }
  for (size_t i = 1; i < getGameGridSizeY() - 1; i++) {
    getGameGrid()[i][0] = fillWord;
    for (size_t j = 1; j < getGameGridSizeX() - 1; j++)
      getGameGrid()[i][j] = fillWord;
    getGameGrid()[i][getGameGridSizeX() - 1] = fillWord;
  }
}

void MenuGame::initScene(void) { scene_.insert(std::make_pair("1", scene_1)); }

void MenuGame::fillWord(const std::string word, size_t x, size_t y) {
  for (size_t i = 0; i < word.size(); i++) {
    getGameGrid()[y][x + i] = word[i];
  }
}

void MenuGame::fillMenu(void) {
  initGameMenu();
  auto tmpIt = scene_.find(currentScene_);
  auto scene = tmpIt->second;
  size_t y = 3, x = getGameGridSizeX() / 2;
  size_t key = 0;

  for (auto &it : scene.args) {
    if (it == "GAME") {
      for (auto &game : gameList_) {
        menuSelected_.insert(std::make_pair(key++, items_s{game, y}));
        fillWord(game, x, y++);
      }
    } else
      fillWord(it, x, y++);
  }
}

int MenuGame::update(void) {
  KEY key = getEvent()->control_key();
  const std::string cursorStyle = config.find("cursor")->second;

  auto mooveCursor = [&](void) {
    cursorY_ -= (key = KEY::UP);
    cursorY_ += (key = KEY::DOWN);
    cursorY_ > menuSelected_.size() - 1 ? cursorY_ = 0 : 0;
    cursorY_ < 0 ? cursorY_ = menuSelected_.size() - 1
                 : menuSelected_.size() - 1;
    return cursorY_;
  };

  if (key == KEY::UP || key == KEY::DOWN) {
    mooveCursor();
    fillWord(cursorStyle, 1, menuSelected_.find(cursorY_)->second.y);
  }
  return 0;
}
