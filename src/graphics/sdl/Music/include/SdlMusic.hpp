// header file for SDLMusic

#pragma once
#include "../../../Gfx/Music/include/Music.hpp"

class SDLMusic : public Music {
public:
  SDLMusic() { std::cout << "hello from music" << std::endl; };
  ~SDLMusic() { std::cout << "bye from music" << std::endl; };
};
