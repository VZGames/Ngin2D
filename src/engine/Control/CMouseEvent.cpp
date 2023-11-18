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
    if (dispatcher->getNextEvent(m_event))
    {
        if (m_event.type == SDL_QUIT)
        {
            CNgin::setRunning(false);
        }
        if (m_event.type == SDL_MOUSEBUTTONDOWN)
        {
            std::lock_guard<std::mutex> lock(m_mtx);
            int mouseX = m_event.button.x;
            int mouseY = m_event.button.y;
            pressed(mouseX, mouseY);
        }
        if (m_event.type == SDL_MOUSEBUTTONUP)
        {
            int mouseX = m_event.button.x;
            int mouseY = m_event.button.y;
            released(mouseX, mouseY);
        }
        if (m_event.type == SDL_MOUSEMOTION)
        {
            int mouseX = m_event.motion.x;
            int mouseY = m_event.motion.y;
            // Handle mouse motion event
            DBG("Mouse moved to (%d, %d)", mouseX, mouseY);
        }
        if (m_event.type == SDL_MOUSEWHEEL)
        {
            if(m_event.wheel.y > 0) // scroll up
            {
                CCamera::instance()->zoom(E_CAMERA_ZOOM::ZOOM_IN);
            }
            else if(m_event.wheel.y < 0) // scroll down
            {
                CCamera::instance()->zoom(E_CAMERA_ZOOM::ZOOM_OUT);
            }
        }
        if (m_event.type == SDL_WINDOWEVENT)
        {
            switch (m_event.window.event) {
            case SDL_WINDOWEVENT_RESIZED:
                break;
            case SDL_WINDOWEVENT_CLOSE:
                break;
            case SDL_WINDOWEVENT_MINIMIZED:
                break;
            case SDL_WINDOWEVENT_MAXIMIZED:
                break;
            default:
                break;
            }
        }
    }
}

void CMouseEvent::pressed(int x, int y)
{
    if (m_event.button.button == SDL_BUTTON_LEFT) {
        // Handle left mouse button down event
        DBG("Left mouse button down at (%d, %d)", x, y);
    }
    else if (m_event.button.button == SDL_BUTTON_RIGHT)
    {
        DBG("Right mouse button down at (%d, %d)", x, y);
    }
}

void CMouseEvent::released(int x, int y)
{
    if (m_event.button.button == SDL_BUTTON_LEFT) {
        // Handle left mouse button up event
        DBG("Left mouse button up at (%d, %d)", x, y);
    }
    else if(m_event.button.button == SDL_BUTTON_RIGHT)
    {
        DBG("Right mouse button up at (%d, %d)", x, y);
    }
}
END_NAMESPACE





