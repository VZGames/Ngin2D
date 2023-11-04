#include "CKeyEvent.h"
#include "CNgin.h"
#include "LoggerDefines.h"
BEGIN_NAMESPACE(GameNgin)
CKeyEvent *CKeyEvent::s_instance = nullptr;
CKeyEvent::CKeyEvent()
{

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
            m_released = 0;
            break;
        case SDL_KEYUP:
            m_released = 1;
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
            float x = 1;
            float y = 1;
            if(m_event.wheel.y > 0) // scroll up
            {
                y = 1.6;
                x = 1.6;
            }
            else if(m_event.wheel.y < 0) // scroll down
            {
                y = 1;
                x = 1;
            }
            SDL_RenderSetScale(CNgin::renderer(), x, y);
            break;
        }

        }
    }
}

bool CKeyEvent::sendEvent(SDL_Scancode numKey)
{
    if (m_state[numKey])
    {
        return 1;
    }
    return 0;
}

const SDL_Event &CKeyEvent::getEvent() const
{
    return m_event;
}

bool CKeyEvent::isReleased() const
{
    return m_released;
}

bool CKeyEvent::isPressed() const
{
    return !m_released;
}
END_NAMESPACE

