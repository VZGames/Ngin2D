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
    std::unordered_map<_TextureID, SDL_Texture*> m_textures;
    void renderFrameThread(void* data);

public:
    static CTexture2DManager *instance();
    
    void drawTile(_TextureID,
                  Point2DF,
                  _TileWidthF,
                  _TileHeightF,
                  _FrameRow,
                  _FrameCol,
                  _Scale,
                  _Angle angle = 0.0f,
                  SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE);

    void drawFrame(_TextureID,
                   Point2DF,
                   _FrameWidthF,
                   _FrameHeightF,
                   _FrameRow,
                   _FrameCol,
                   _Scale,
                   _Angle angle = 0.0f,
                   SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE);

    void drawRect(Point2DF, _FrameWidthF, _FrameHeightF, _Scale);
    void drawPolygon(std::vector<Vector2D<float>>, _Scale);
//    Implement ITextureManager Interfaces
public:
    virtual bool loadTexture(_TextureID, _TextureSource) override;
};
END_NAMESPACE

#endif // CTEXTURE2DMANAGER_H
