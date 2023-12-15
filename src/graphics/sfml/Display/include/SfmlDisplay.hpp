// header file for SfmlDisplay

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Glyph.hpp>
#include <SFML/Main.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "../../../Gfx/Display/include/Display.hpp"

class SFMLDisplay : public Display {
  public:
    SFMLDisplay();
    ~SFMLDisplay();
    void init_gfx(std::vector<std::string> &gameGrid) override;
    void display_score(int score, int pos_x, int pos_y) override;
    int update(std::vector<std::string> &gameGrid) override;
    void micro_sleep(int sleep) override;
    void display_end(int seconds, int score, int maxx, int maxy) override;
    void close_window(void) override;
    void display_chara(int x, int y, char chara) override;
    void clear_window() override;
    sf::RenderWindow &getWindow()
    {
        return window_;
    };

  private:
    sf::RenderWindow window_;
    sf::Font font_;
    std::vector<sf::Text> texts_;
};
