// header file for SfmlMusic

#pragma once
#include "../../../Gfx/Music/include/Music.hpp"

class SFMLMusic : public Music {
public:
  SFMLMusic() { std::cout << "hello from music" << std::endl; };
  ~SFMLMusic() { std::cout << "bye from music" << std::endl; };
};
