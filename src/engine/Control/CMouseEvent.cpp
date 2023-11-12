#include "CMouseEvent.h"
#include "CCamera.h"
#include "CNgin.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(engine)
CMouseEvent *CMouseEvent::s_instance = nullptr;
CMouseEvent::CMouseEvent()
{

}

CMouseEvent *CMouseEvent::instance()
{
    return s_instance = (s_instance == nullptr)? new CMouseEvent():s_instance;
}

void CMouseEvent::processEvents(CEventDispatcher *dispatcher)
{
    LOCK_GUARD(m_mtx);
    if (dispatcher->getNextEvent(m_event))
    {
        switch (m_event.type)
        {
        case SDL_QUIT:
        {
            CNgin::setRunning(false);
            break;
        }
        case SDL_MOUSEBUTTONDOWN:
        {
            int mouseX = m_event.button.x;
            int mouseY = m_event.button.y;
            if (m_event.button.button == SDL_BUTTON_LEFT) {
                // Handle left mouse button down event
                DBG("Left mouse button down at (%d, %d)", mouseX, mouseY);
            }
            else if (m_event.button.button == SDL_BUTTON_RIGHT)
            {
                DBG("Right mouse button down at (%d, %d)", mouseX, mouseY);
            }
            break;
        }
        case SDL_MOUSEBUTTONUP:
        {
            int mouseX = m_event.button.x;
            int mouseY = m_event.button.y;
            if (m_event.button.button == SDL_BUTTON_LEFT) {
                // Handle left mouse button up event
                DBG("Left mouse button up at (%d, %d)", mouseX, mouseY);
            }
            else if(m_event.button.button == SDL_BUTTON_RIGHT)
            {
                DBG("Right mouse button up at (%d, %d)", mouseX, mouseY);
            }
            break;
        }
        case SDL_MOUSEMOTION:
        {
            int mouseX = m_event.motion.x;
            int mouseY = m_event.motion.y;
            // Handle mouse motion event
            DBG("Mouse moved to (%d, %d)", mouseX, mouseY);
            break;
        }
        case SDL_MOUSEWHEEL:
        {
            if(m_event.wheel.y > 0) // scroll up
            {
                CCamera::instance()->zoom(E_CAMERA_ZOOM::ZOOM_IN);
            }
            else if(m_event.wheel.y < 0) // scroll down
            {
                CCamera::instance()->zoom(E_CAMERA_ZOOM::ZOOM_OUT);
            }
            break;
        }
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


