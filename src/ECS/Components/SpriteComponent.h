#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct SpriteComponent: public ComponentBase<SpriteComponent>
{
    SpriteComponent(const char *textureId, const char *source, int width, int height): textureId(textureId),
        source(source),
        frameWidth(width),
        frameHeight(height)
    {}
    const char *textureId;
    const char *source;
    int frameWidth, frameHeight;
    int col = 0;
    int row = 0;
};
}

#endif // SPRITECOMPONENT_H
