#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct SpriteComponent: public ComponentBase<SpriteComponent>
{
    SpriteComponent(const char *textureId, const char *source, int width, int height, int frameCount, int frameSpeed = 200): textureId(textureId),
        source(source),
        frameWidth(width),
        frameHeight(height),
        frameCount(frameCount),
        frameSpeed(frameSpeed)
    {}
    const char *textureId;
    const char *source;
    int frameWidth, frameHeight, frameCount;
    int col = 0;
    int row = 0;
    int frameSpeed;
};
}

#endif // SPRITECOMPONENT_H
