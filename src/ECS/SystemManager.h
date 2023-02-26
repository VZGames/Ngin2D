#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include "Systems/Systems.h"

namespace nginvz
{
class SystemManager
{
public:
    SystemManager();

    virtual void init(){};
    virtual void update(float deltaTime){};
    virtual void render(){};
};
}

#endif // SYSTEMMANAGER_H
