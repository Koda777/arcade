/*
** EPITECH PROJECT, 2023
** graphics
** File description:
** NcursesMusic.hpp
*/
#pragma once
#include "../../../Gfx/Music/include/Music.hpp"

class NcursesMusic : public Music {
public:
  NcursesMusic() { std::cout << "hello from music" << std::endl; };
  ~NcursesMusic() { std::cout << "bye from music" << std::endl; };
};
