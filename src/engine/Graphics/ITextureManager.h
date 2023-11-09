#ifndef ITEXTUREMANAGER_H
#define ITEXTUREMANAGER_H

#include "CommonDefine.h"
#include "Alias.h"

BEGIN_NAMESPACE(engine)
class ITextureManager
{
public:
    virtual bool loadTexture(TextureID, TextureSource) = 0;
};
END_NAMESPACE

#endif // ITEXTUREMANAGER_H
