#ifndef CTEXTURE2DMANAGER_H
#define CTEXTURE2DMANAGER_H

#include "CommonDefine.h"
#include "Alias.h"
#include "ITextureManager.h"
#include "Math/point2D.h"

BEGIN_NAMESPACE(GameNgin)
class CTexture2DManager: public ITextureManager
{
public:
    CTexture2DManager();

    void drawTile(TextureID, Point2DI, TileWidth, TileHeight, TileRow, TileCol);
    void drawFrame(TextureID, Point2DI, FrameWidth, FrameHeight, FrameRow, FrameCol);

//    Implement ITextureManager Interfaces
public:
    virtual bool loadTexture(TextureID, TextureSource) override;
};
END_NAMESPACE

#endif // CTEXTURE2DMANAGER_H
