#include "../include/SfmlDisplay.hpp"
#include <vector>

SFMLDisplay::SFMLDisplay()
{
    window_.create(sf::VideoMode(800, 600), "My Game");
    window_.setFramerateLimit(60);
    if (!font_.loadFromFile("assets/Font.ttf"))
        std::cerr << "Error loading font" << std::endl;
}

SFMLDisplay::~SFMLDisplay()
{
    window_.close();
}

void SFMLDisplay::init_gfx(std::vector<std::string> &gameGrid)
{
    for (size_t i = 0; i < gameGrid.size(); i++) {
        sf::Text text;
        text.setFont(font_);
        text.setString(gameGrid[i]);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(50, i * 24 + 50);
        texts_.push_back(text);
    }
}

void SFMLDisplay::display_score(int score, int pos_x, int pos_y)
{
    sf::Text text;
    text.setFont(font_);
    text.setString("Score: " + std::to_string(score));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(pos_x, pos_y);
    texts_.push_back(text);
}

int SFMLDisplay::update(std::vector<std::string> &gameGrid)
{
    texts_.clear();
    for (size_t i = 0; i < gameGrid.size(); i++) {
        sf::Text text;
        text.setFont(font_);
        text.setString(gameGrid[i]);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(50, i * 24 + 50);
        texts_.push_back(text);
    }

    window_.clear(sf::Color::Black);
    for (const auto &text : texts_) {
        window_.draw(text);
    }
    window_.display();
    return 0;
}

void SFMLDisplay::micro_sleep(int sleep)
{
    sf::sleep(sf::microseconds(sleep));
}

void SFMLDisplay::display_end(int seconds, int score, int maxx, int maxy)
{
    sf::Text text;
    text.setFont(font_);
    text.setString("Game Over!");
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::Red);
    text.setPosition(maxx / 2 - 150, maxy / 2 - 50);
    texts_.push_back(text);

    text.setString("Score: " + std::to_string(score));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(maxx / 2 - 50, maxy / 2 + 50);
    texts_.push_back(text);

    text.setString("Time: " + std::to_string(seconds) + " seconds");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(maxx / 2 - 75, maxy / 2 + 100);
    texts_.push_back(text);

    window_.clear(sf::Color::Black);
    for (const auto &text : texts_) {
        window_.draw(text);
    }
    window_.display();
    sf::sleep(sf::seconds(5));
}

void SFMLDisplay::close_window()
{
    window_.close();
}

void SFMLDisplay::display_chara(int x, int y, char chara)
{
    sf::Text text;
    text.setFont(font_);
    text.setString(std::string(1, chara));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);
    texts_.push_back(text);
}

void SFMLDisplay::clear_window()
{
    texts_.clear();
}
