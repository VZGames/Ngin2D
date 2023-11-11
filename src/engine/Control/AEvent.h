#ifndef AEVENT_H
#define AEVENT_H

#include "CommonDefine.h"
#include "CEventDispatcher.h"

BEGIN_NAMESPACE(engine)
class AEvent
{
protected:
    SDL_Event   m_event;
    std::mutex  m_mtx;

    std::condition_variable m_c;

public:
    virtual void processEvents(CEventDispatcher*) = 0;
};
END_NAMESPACE

#endif // AEVENT_H
