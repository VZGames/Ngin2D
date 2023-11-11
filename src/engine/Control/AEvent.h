#ifndef AEVENT_H
#define AEVENT_H

#include "CommonDefine.h"
#include <SDL2/SDL_events.h>
#include <mutex>

BEGIN_NAMESPACE(engine)
class AEvent
{
protected:
    SDL_Event  m_event;
    std::mutex m_mtx;
public:
    virtual void listen() = 0;
};
END_NAMESPACE

#endif // AEVENT_H
