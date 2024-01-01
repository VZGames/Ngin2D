#include "CKeyEvent.h"
#include "LoggerDefines.h"

using namespace engine;
CKeyEvent *CKeyEvent::s_instance = nullptr;
CKeyEvent::CKeyEvent()
{
    m_state = SDL_GetKeyboardState(nullptr);
}

CKeyEvent *CKeyEvent::instance()
{
    return s_instance = (s_instance == nullptr) ? new CKeyEvent() : s_instance;
}

bool CKeyEvent::sendEvent(uint32_t key)
{
    if (m_inputs.find(key) == m_inputs.end())
    {
        return false;
    }

    if (m_state[key] || m_event.type == key)
    {
        m_inputs.at(key)();
        return true;
    }
    return false;
}

void CKeyEvent::processEvents(CEventDispatcher *dispatcher)
{
    LOCK_GUARD(m_mtx)
    if (dispatcher->getNextEvent(m_event))
    {
        if (m_event.type == SDL_KEYDOWN)
        {
            keyDown();
        }
        if (m_event.type == SDL_KEYUP)
        {
            keyUp();
        }
    }
}

void CKeyEvent::keyDown()
{
    DBG("Key Down")
}

void CKeyEvent::keyUp()
{
    DBG("Key Up");
}


