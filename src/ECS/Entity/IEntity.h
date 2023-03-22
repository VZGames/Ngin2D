#ifndef IENTITY_H
#define IENTITY_H

#include "ECS/Components/Components.h"

namespace ngin2D {
class IEntity
{
public:
    virtual void init(){};
    virtual void handleKeyEvent() = 0;
    virtual void handleMouseEvent() = 0;
};
}
#endif // IENTITY_H
