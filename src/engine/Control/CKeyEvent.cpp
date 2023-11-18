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
            keyDown();
            break;
        }
        case SDL_KEYUP:
        {
            DBG("Key Up")
            keyUp();
            break;
        }
        default:
            break;
        }
    }
}


void CKeyEvent::keyDown()
{
    SDL_Scancode numKey = m_event.key.keysym.scancode;
    if(sendEvent(numKey))
    {
        m_inputs[numKey]();
    }
    else
    {
        m_inputs[SDL_SCANCODE_UNKNOWN]();
    }
}

void CKeyEvent::keyUp()
{
    m_event.type = SDL_KEYDOWN;
    m_event.key.keysym.scancode = SDL_SCANCODE_UNKNOWN;
    m_event.key.keysym.sym = SDLK_UNKNOWN;
    m_event.key.keysym.mod = KMOD_NONE;

    SDL_PushEvent(&m_event);
}

END_NAMESPACE


