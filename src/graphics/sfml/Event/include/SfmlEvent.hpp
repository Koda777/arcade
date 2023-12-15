// header file for SfmlEvent

#pragma once
#include <SFML/Window/Window.hpp>
#include <memory>
#include "../../../Gfx/Event/include/Event.hpp"

class SFMLEvent : public Event {
  public:
    SFMLEvent() {};
    ~SFMLEvent() {};
    KEY control_key(void) override;
    std::unique_ptr<sf::Window> &getWindow() { return _window; };

  private:
    std::unique_ptr<sf::Window> _window;
};
