#ifndef CKEYEVENT_H
#define CKEYEVENT_H

#include "CommonDefine.h"
#include <SDL2/SDL_events.h>

BEGIN_NAMESPACE(GameNgin)
class CKeyEvent
{
private:
    CKeyEvent();
    static CKeyEvent        *s_instance;
    const Uint8             *m_state;
    bool                    m_released = 1;
    SDL_Event               m_event;
public:
    static CKeyEvent *instance();
    void listen();

    bool sendEvent(SDL_Scancode);

    const SDL_Event &getEvent() const;

    bool isReleased() const;
    bool isPressed() const;

};
END_NAMESPACE
#endif // CKEYEVENT_H