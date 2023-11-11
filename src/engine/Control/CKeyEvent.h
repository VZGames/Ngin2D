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

public:
    static CKeyEvent *instance();

    bool sendEvent(SDL_Scancode);

public:
    virtual void processEvents(CEventDispatcher*) override;
};
END_NAMESPACE
#endif // CKEYEVENT_H
