#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "ECS/Entity/Entity.h"

namespace ngin2D {
class ISystem
{
protected:
    std::vector<Entity> m_entities;

public:
    virtual void init(){};
    virtual void update(float dt) = 0;
    virtual void render(){};
};
}
#endif // SYSTEM_H
