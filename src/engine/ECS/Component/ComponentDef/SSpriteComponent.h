#ifndef SSPRITECOMPONENT_H
#define SSPRITECOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"

BEGIN_NAMESPACE(engine)
struct SSpriteComponent: public  CComponent
{
    SSpriteComponent(const char *textureId, const char *source, float width, float height, int frameCount, int frameSpeed = 200):
        textureId(textureId),
        source(source),
        frameWidth(width),
        frameHeight(height),
        frameCount(frameCount),
        frameSpeed(frameSpeed)
    {
        m_name = __FUNCTION__;
    }
    const char *textureId;
    const char *source;
    float frameWidth, frameHeight;
    int frameCount;
    int col = 0;
    int row = 0;
    int frameSpeed;
    float scale = 1;
};
END_NAMESPACE

#endif // SSPRITECOMPONENT_H
