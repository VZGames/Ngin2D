#include "CKeyEvent.h"
#include "CNgin.h"
#include "LoggerDefines.h"
#include "CCamera.h"

BEGIN_NAMESPACE(Ngin)
CKeyEvent *CKeyEvent::s_instance = nullptr;
CKeyEvent::CKeyEvent()
{
    m_state = SDL_GetKeyboardState(nullptr);
}

CKeyEvent *CKeyEvent::instance()
{
    return s_instance = (s_instance == nullptr)? new CKeyEvent():s_instance;
}

void CKeyEvent::listen()
{
    while (SDL_PollEvent(&m_event))
    {
        switch (m_event.type)
        {
        case SDL_QUIT:
            CNgin::setRunning(false);
            break;
        case SDL_KEYDOWN:
            m_released = false;
            m_pressed  = true;
            break;
        case SDL_KEYUP:
            m_released = true;
            m_pressed  = false;
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
        case SDL_MOUSEWHEEL:
        {
            if(m_event.wheel.y > 0) // scroll up
            {
                CCamera::instance()->zoom(E_CAMERA_ZOOM::ZOOM_OUT);
            }
            else if(m_event.wheel.y < 0) // scroll down
            {
                CCamera::instance()->zoom(E_CAMERA_ZOOM::ZOOM_IN);
            }
            break;
        }
        default:
            break;
        }
    }
}

bool CKeyEvent::sendEvent(SDL_Scancode numKey)
{
    if (m_state[numKey])
    {
        return true;
    }
    return false;
}

CKeyEvent *CKeyEvent::registerKeyInput(SDL_Scancode numKey, std::function<void (void)> handle)
{
    if(m_inputs.find(numKey) == m_inputs.end())
    {
        m_inputs[numKey] = handle;
    }
    return this;
}

bool CKeyEvent::isReleased() const
{
    return m_released;
}

bool CKeyEvent::isPressed() const
{
    return m_pressed;
}
END_NAMESPACE



