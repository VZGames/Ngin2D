#ifndef CTEXTURE2DMANAGER_H
#define CTEXTURE2DMANAGER_H

#include "CommonDefine.h"
#include "Alias.h"
#include "ATextureManager.h"
#include "Math/point2D.h"

BEGIN_NAMESPACE(engine)
class CTexture2DManager: public ATextureManager
{
private:
    CTexture2DManager();
    static CTexture2DManager *s_instance;
    std::unordered_map<TextureID, SDL_Texture*> m_textures;
    void renderFrameThread(void* data);

public:
    static CTexture2DManager *instance();

    void drawTile(TextureID, Point2DF, TileWidth, TileHeight, TileRow, TileCol, Angle angle = 0.0f, SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE);
    void drawFrame(TextureID, Point2DF, FrameWidth, FrameHeight, FrameRow, FrameCol, Angle angle = 0.0f, SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE);
    void drawRect(Point2DF, FrameWidth, FrameHeight);
    void drawPolygon(std::vector<Vector2DF>);
//    Implement ITextureManager Interfaces
public:
    virtual bool loadTexture(TextureID, TextureSource) override;
};
END_NAMESPACE

#endif // CTEXTURE2DMANAGER_H
