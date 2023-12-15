// source file for SfmlEvent

#include "../include/SfmlEvent.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "IEvent.hpp"

KEY SFMLEvent::control_key()
{
    return NONE;
}