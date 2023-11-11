#include "CKeyEvent.h"
#include "LoggerDefines.h"
#include "CNgin.h"

BEGIN_NAMESPACE(engine)
CKeyEvent *CKeyEvent::s_instance = nullptr;
bool CKeyEvent::s_toggle_status = false;
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

bool CKeyEvent::isPressed()
{
    return s_toggle_status == SDL_PRESSED;
}

bool CKeyEvent::isReleased()
{
    return s_toggle_status == SDL_RELEASED;
}

void CKeyEvent::processEvents(CEventDispatcher *dispatcher)
{
    std::lock_guard<std::mutex> lock(m_mtx);
//    std::unique_lock<std::mutex> lock(m_mtx);
    if (dispatcher->getNextEvent(m_event))
    {
        MORGAN_DEBUG("")
        switch (m_event.type)
        {
        case SDL_QUIT:
        {
            CNgin::setRunning(false);
            break;
        }
        case SDL_KEYDOWN:
        {
            s_toggle_status = true;
            break;
        }
        case SDL_KEYUP:
        {
            s_toggle_status = false;
            break;
        }
        default:
            break;
        }
    }
//    lock.unlock();
}

END_NAMESPACE




