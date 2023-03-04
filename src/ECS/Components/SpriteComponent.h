#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct SpriteComponent: public ComponentBase<SpriteComponent>
{
    SpriteComponent(const char *textureId, const char *source, int width, int height, int col, int row): textureId(textureId),
        source(source),
        frameWidth(width),
        frameHeight(height),
        col(col),
        row(row)
    {}
    const char *textureId;
    const char *source;
    int frameWidth, frameHeight;
    int col, row;
};
}

#endif // SPRITECOMPONENT_H
