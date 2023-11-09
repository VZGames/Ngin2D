#ifndef CKEYEVENT_H
#define CKEYEVENT_H

#include "CommonDefine.h"
#include "LoggerDefines.h"
#include <SDL2/SDL_events.h>

BEGIN_NAMESPACE(engine)
class CKeyEvent
{
private:
    CKeyEvent();
    static CKeyEvent                                            *s_instance;
    const Uint8                                                 *m_state;
    static bool                                                 s_toggle_status;
    SDL_Event                                                   m_event;

public:
    static CKeyEvent *instance();
    void listen();

    bool sendEvent(SDL_Scancode);

    static bool isPressed();
    static bool isReleased();
};
END_NAMESPACE
#endif // CKEYEVENT_H
