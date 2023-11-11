#include "CKeyEvent.h"
#include "CNgin.h"
#include "LoggerDefines.h"

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

void CKeyEvent::listen()
{
//    std::lock_guard<std::mutex> lck(m_mtx);
    while (SDL_PollEvent(&m_event))
    {
        switch (m_event.type)
        {
        case SDL_QUIT:
            CNgin::setRunning(false);
            break;
        case SDL_KEYDOWN:
            s_toggle_status = true;
            break;
        case SDL_KEYUP:
            s_toggle_status = false;
            break;
        case SDL_WINDOWEVENT:
            switch (m_event.window.event) {
            case SDL_WINDOWEVENT_RESIZED:
                break;
            case SDL_WINDOWEVENT_CLOSE:
                break;
            case SDL_WINDOWEVENT_MINIMIZED:
                break;
            case SDL_WINDOWEVENT_MAXIMIZED:
                break;
            }
            break;
        default:
            break;
        }
    }
}

END_NAMESPACE




