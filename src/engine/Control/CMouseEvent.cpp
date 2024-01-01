#include "CMouseEvent.h"
#include "Camera/CCameraSys.h"
#include "CNgin.h"
#include <LoggerDefines.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>
#include "Define/Assets/DefineWidgets.h"

using namespace engine;
CMouseEvent *CMouseEvent::s_instance = nullptr;
CMouseEvent::CMouseEvent()
{
    LOCK_GUARD(m_mtx)
    float scale = CCameraSys::instance()->scale();
    float width = 16 * scale;
    float height = 16 * scale;
    m_surface = IMG_Load(SQUARE_MOUSE_SELECT);
    m_newSurface = SDL_CreateRGBSurface(0, width, height,
                                                   m_surface->format->BitsPerPixel,
                                                   m_surface->format->Rmask,
                                                   m_surface->format->Gmask,
                                                   m_surface->format->Bmask,
                                                   m_surface->format->Amask);
    if (m_surface == NULL) {
        DBG("Failed to load custom cursor image: %s\n", IMG_GetError())
    }
    else
    {
        m_cursor_rect.x = 0;
        m_cursor_rect.y = 0;
        m_cursor_rect.w = width;
        m_cursor_rect.h = height;

        SDL_BlitScaled(m_surface, NULL, m_newSurface, &m_cursor_rect);

        m_cursor = SDL_CreateColorCursor(m_newSurface, 0, 0);
        SDL_SetCursor(m_cursor);
    }
}

CMouseEvent::~CMouseEvent()
{
    SDL_FreeCursor(m_cursor);
    SDL_FreeSurface(m_newSurface);
    SDL_FreeSurface(m_surface);
}

CMouseEvent *CMouseEvent::instance()
{
    return s_instance = (s_instance == nullptr)? new CMouseEvent():s_instance;
}

void CMouseEvent::processEvents(CEventDispatcher *dispatcher)
{
    LOCK_GUARD(m_mtx)
    if (dispatcher->getNextEvent(m_event))
    {
        switch (m_event.type) {
        case SDL_QUIT:
            break;
        case SDL_MOUSEBUTTONDOWN:
            pressed();
            break;
        case SDL_MOUSEBUTTONUP:
            released();
            break;
        case SDL_MOUSEWHEEL:
            wheel();
            break;
        case SDL_WINDOWEVENT:
            windowEvent();
            break;
        default:
            break;
        }
    }
}

void CMouseEvent::quit()
{
    CNgin::setRunning(false);
}

void CMouseEvent::pressed()
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
}

void CMouseEvent::released()
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
}

void CMouseEvent::wheel()
{
    float scale{0.0f};
    if(m_event.wheel.y > 0) // scroll up
    {
        scale = CCameraSys::instance()->zoom(E_CAMERA_ZOOM::ZOOM_IN);
    }
    else if(m_event.wheel.y < 0) // scroll down
    {
        scale = CCameraSys::instance()->zoom(E_CAMERA_ZOOM::ZOOM_OUT);
    }
    m_cursor_rect.w = 16 * scale;
    m_cursor_rect.h = 16 * scale;
    m_newSurface = SDL_CreateRGBSurface(0,m_cursor_rect.w, m_cursor_rect.h,
                                        m_surface->format->BitsPerPixel,
                                        m_surface->format->Rmask,
                                        m_surface->format->Gmask,
                                        m_surface->format->Bmask,
                                        m_surface->format->Amask);

    m_newSurface->w = m_cursor_rect.w;
    m_newSurface->h = m_cursor_rect.h;
    SDL_BlitScaled(m_surface, NULL, m_newSurface, &m_cursor_rect);
    m_cursor = SDL_CreateColorCursor(m_newSurface, 0, 0);
    SDL_SetCursor(m_cursor);

}

void CMouseEvent::windowEvent()
{
    switch (m_event.window.event) {
    case SDL_WINDOWEVENT_RESIZED:
        break;
    case SDL_WINDOWEVENT_CLOSE:
        quit();
        break;
    case SDL_WINDOWEVENT_MINIMIZED:
        break;
    case SDL_WINDOWEVENT_MAXIMIZED:
        break;
    default:
        break;
    }
}













