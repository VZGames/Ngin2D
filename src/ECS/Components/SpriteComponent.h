#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct SpriteComponent: public ComponentBase<SpriteComponent>
{
    SpriteComponent(const char* source): source(source){}
    const char* source;
};
}

#endif // SPRITECOMPONENT_H
