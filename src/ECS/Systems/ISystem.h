#ifndef SYSTEM_H
#define SYSTEM_H

#include "Core/BObject/BObject.h"

namespace ngin2D {
class ISystem: public BObject
{
public:
    virtual void init(){};
    virtual void update(float dt) = 0;
    virtual void render(){};
};
}
#endif // SYSTEM_H
