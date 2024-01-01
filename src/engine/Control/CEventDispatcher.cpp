#include "CEventDispatcher.h"
#include "LoggerDefines.h"
using namespace engine;
CEventDispatcher *CEventDispatcher::s_instance = nullptr;
CEventDispatcher::CEventDispatcher()
{

}

CEventDispatcher *CEventDispatcher::instance()
{
    return s_instance = (s_instance == nullptr)? new CEventDispatcher():s_instance;
}

void CEventDispatcher::listen()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        LOCK_GUARD(m_mutex)
        // Push the event to the queue
        m_events.push(event);
    }
}

bool CEventDispatcher::getNextEvent(SDL_Event &event)
{
    LOCK_GUARD(m_mutex)
    if (!m_events.empty()) {
        event = m_events.front();
        m_events.pop();
        return true;
    }
    return false;
}



