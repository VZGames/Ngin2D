#ifndef CTEXTURE2DMANAGER_H
#define CTEXTURE2DMANAGER_H

#include "CommonDefine.h"
#include "Alias.h"
#include "ITextureManager.h"
#include "Math/point2D.h"

BEGIN_NAMESPACE(GameNgin)
class CTexture2DManager: public ITextureManager
{
private:
    CTexture2DManager();
    static CTexture2DManager *s_instance;
    std::unordered_map<TextureID, SDL_Texture*> m_textures;

public:
    static CTexture2DManager *instance();

    void drawTile(TextureID, Point2DI, TileWidth, TileHeight, TileRow, TileCol);
    void drawFrame(TextureID, Point2DI, FrameWidth, FrameHeight, FrameRow, FrameCol, Angle = 0.0f, SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE);

//    Implement ITextureManager Interfaces
public:
    virtual bool loadTexture(TextureID, TextureSource) override;
};
END_NAMESPACE

#endif // CTEXTURE2DMANAGER_H
