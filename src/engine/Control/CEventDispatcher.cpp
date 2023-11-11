#include "CEventDispatcher.h"
#include "Logger/LoggerDefines.h"
BEGIN_NAMESPACE(engine)
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
        // Push the event to the queue
        m_events.push(event);
    }
}

bool CEventDispatcher::getNextEvent(SDL_Event &event)
{
    if (!m_events.empty()) {
        event = m_events.front();
        m_events.pop();
        return true;
    }
    return false;
}

END_NAMESPACE

