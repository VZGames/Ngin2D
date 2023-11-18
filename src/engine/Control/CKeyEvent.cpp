#include "CKeyEvent.h"
#include "LoggerDefines.h"
#include "CNgin.h"

BEGIN_NAMESPACE(engine)
CKeyEvent *CKeyEvent::s_instance = nullptr;
CKeyEvent::CKeyEvent()
{
    m_state = SDL_GetKeyboardState(nullptr);
}

CKeyEvent *CKeyEvent::instance()
{
    return s_instance = (s_instance == nullptr)? new CKeyEvent():s_instance;
}

bool CKeyEvent::sendEvent(SDL_Scancode numKey)
{
    if (m_inputs.find(numKey) == m_inputs.end())
    {
        return false;
    }

    if (m_state[numKey])
    {
        return true;
    }
    return false;
}

void CKeyEvent::processEvents(CEventDispatcher *dispatcher)
{
    if (dispatcher->getNextEvent(m_event))
    {
        if (m_event.type == SDL_KEYDOWN)
        {
            std::lock_guard<std::mutex> lock(m_mtx);
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
    SDL_Scancode numKey = m_event.key.keysym.scancode;
    if(sendEvent(numKey))
    {
        m_inputs[numKey]();
    }
}

void CKeyEvent::keyUp()
{
    DBG("Key Up");

}

END_NAMESPACE


