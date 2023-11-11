#ifndef CTEXTURE3DMANAGER_H
#define CTEXTURE3DMANAGER_H

#include "CommonDefine.h"
#include "ATextureManager.h"

BEGIN_NAMESPACE(engine)
class CTexture3DManager: public ATextureManager
{
public:
    CTexture3DManager();

    //    Implement ITextureManager Interfaces
public:
    virtual bool loadTexture(TextureID, TextureSource) override;
};
END_NAMESPACE

#endif // CTEXTURE3DMANAGER_H
