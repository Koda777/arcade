// header file for SDLEvent

#pragma once
#include "../../../Gfx/Event/include/Event.hpp"

class SDLEvent : public Event {
  public:
    SDLEvent() {};
    ~SDLEvent() {};
    KEY control_key(void) override;
};
