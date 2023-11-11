#ifndef CKEYEVENT_H
#define CKEYEVENT_H

#include "CommonDefine.h"
#include "LoggerDefines.h"
#include "AEvent.h"

BEGIN_NAMESPACE(engine)
class CKeyEvent: public AEvent
{
private:
    CKeyEvent();
    static CKeyEvent                                            *s_instance;
    const Uint8                                                 *m_state;
    static bool                                                 s_toggle_status;

public:
    static CKeyEvent *instance();

    bool sendEvent(SDL_Scancode);

    static bool isPressed();
    static bool isReleased();

public:
    virtual void listen() override;
};
END_NAMESPACE
#endif // CKEYEVENT_H
