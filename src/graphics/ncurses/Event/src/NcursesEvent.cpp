// source file for NcursesEvent

#include "../include/NcursesEvent.hpp"
#include "IEvent.hpp"

KEY NcursesEvent::control_key()
{
    int ch = getch();
    std::cout << ch << std::endl;
    switch (ch) {
        case UP: return UP;
        case DOWN: return DOWN;
        case LEFT: return LEFT;
        case RIGHT: return RIGHT;
        case PREV_GAME: return PREV_GAME;
        case NEXT_GAME: return NEXT_GAME;
        case PREV_GRAPHIC: return PREV_GRAPHIC;
        case NEXT_GRAPHIC: return NEXT_GRAPHIC;
        default: return NONE;
    }
}