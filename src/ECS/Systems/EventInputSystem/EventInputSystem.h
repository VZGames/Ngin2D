#ifndef EVENTINPUTSYSTEM_H
#define EVENTINPUTSYSTEM_H

#include "../ISystem.h"

namespace ngin2D
{
class EventInputSystem: public ISystem
{
public:
    EventInputSystem();

    // ISystem interface
public:
    virtual void update(float dt) override;
};
}

#endif // EVENTINPUTSYSTEM_H
