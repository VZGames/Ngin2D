#ifndef EVENTINPUTSYSTEM_H
#define EVENTINPUTSYSTEM_H

#include "../ISystem.h"
#include "SDL2/SDL_events.h"

namespace ngin2D
{
class EventInputSystem: public ISystem
{
public:
    EventInputSystem();

    // ISystem interface
public:
    virtual void update(float dt) override;

private:
    const Uint8 *keyBoardState;
    SDL_Event event;
};
}

#endif // EVENTINPUTSYSTEM_H
