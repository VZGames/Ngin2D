#include "CKeyEvent.h"
#include <LoggerDefines.h>
#include "CNgin.h"

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
        switch (m_event.type)
        {
        case SDL_KEYDOWN:
            keyDown();
            break;
        case SDL_KEYUP:
            keyUp();
            break;
        default:
            break;
        }
    }
}

void CKeyEvent::keyDown()
{
    DBG("Key Down")
}

void CKeyEvent::keyUp()
{
    if (m_event.key.keysym.sym == SDLK_ESCAPE)
    {
        CNgin::setRunning(false);
    }
    DBG("Key Up");
}


