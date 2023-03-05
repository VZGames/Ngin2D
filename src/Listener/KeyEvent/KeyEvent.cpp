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
            keyDown = 1;
            break;
        case SDL_KEYUP:
            keyDown = 0;
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

bool KeyEvent::getKeyDown() const
{
    return keyDown;
}

const SDL_Event &KeyEvent::getEvent() const
{
    return event;
}
}
