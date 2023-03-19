#ifndef KEYEVENT_H
#define KEYEVENT_H

#include "SDL2/SDL_events.h"

namespace ngin2D
{
class KeyEvent
{
public:
    static KeyEvent *instance();
    void listen();

    bool sendEvent(SDL_Scancode numKey);

    const SDL_Event &getEvent() const;

    bool isReleased() const;
    bool isPressed() const;

private:
    KeyEvent();
    ~KeyEvent();
    static KeyEvent *s_instance;
    const Uint8 *keyBoardState;
    bool released = 1;
    SDL_Event event;
};

}

#endif // KEYEVENT_H
