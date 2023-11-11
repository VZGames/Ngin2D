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
    if (m_state[numKey])
    {
        return true;
    }
    return false;
}

void CKeyEvent::processEvents(CEventDispatcher *dispatcher)
{
    std::lock_guard<std::mutex> lock(m_mtx);
    if (dispatcher->getNextEvent(m_event))
    {
        switch (m_event.type)
        {
        case SDL_QUIT:
        {
            CNgin::setRunning(false);
            DBG("Quit event")
            break;
        }
        case SDL_KEYDOWN:
        {
            DBG("Key Down")
            break;
        }
        case SDL_KEYUP:
        {
            DBG("Key Up")
            break;
        }
        default:
            break;
        }
    }
}

END_NAMESPACE




