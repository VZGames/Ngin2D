#include "KeyEvent.h"
#include <iostream>;
#include "../../Game/Game.h"

namespace ngin2D {
KeyEvent *KeyEvent::s_instance = nullptr;
KeyEvent *KeyEvent::instance()
{
    return s_instance = (s_instance == nullptr)? new KeyEvent():s_instance;
}

void KeyEvent::listen()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            Game::s_gameRunning = false;
            break;
        case SDL_KEYDOWN:
            released = 0;
            break;
        case SDL_KEYUP:
            released = 1;
            break;
        }
    }
}

bool KeyEvent::sendEvent(SDL_Scancode numKey)
{

    if (keyBoardState[numKey])
    {
        return 1;
    }
    return 0;
}

KeyEvent::KeyEvent()
{
    keyBoardState = SDL_GetKeyboardState(nullptr);
}

KeyEvent::~KeyEvent()
{
    delete keyBoardState;
    keyBoardState = NULL;
}

bool KeyEvent::isReleased() const
{
    return released;
}

const SDL_Event &KeyEvent::getEvent() const
{
    return event;
}
}
