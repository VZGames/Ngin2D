#include "CTexture2DManager.h"
#include "LoggerDefines.h"
#include "CNgin.h"
#include "CCamera.h"

BEGIN_NAMESPACE(Ngin)
CTexture2DManager *CTexture2DManager::s_instance = nullptr;
CTexture2DManager::CTexture2DManager()
{

}

CTexture2DManager *CTexture2DManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CTexture2DManager() : s_instance;
}

void CTexture2DManager::renderFrameThread(void *data)
{

}

void CTexture2DManager::drawTile(TextureID id, Point2DI pos, TileWidth w, TileHeight h, TileRow r, TileCol c)
{
    UNUSED(id);
    UNUSED(pos);
    UNUSED(w);
    UNUSED(h);
    UNUSED(r);
    UNUSED(c);
}

void CTexture2DManager::drawFrame(TextureID id, Point2DF pos, FrameWidth w, FrameHeight h, FrameRow r, FrameCol c, Angle angle, SDL_RendererFlip flip)
{
    int frameX = w * c;
    int frameY = h * r;
    float scale = CCamera::instance()->scale();
    SDL_Rect srcRect = {frameX, frameY, w, h};
    SDL_FRect destRect = {
        pos.getX(),
        pos.getY(),
        (float)w * scale,
        (float)h * scale
    };

    SDL_RenderCopyExF(CNgin::renderer(), m_textures[id], &srcRect, &destRect, angle, NULL, flip);
}

bool CTexture2DManager::loadTexture(TextureID id, TextureSource source)
{

    if(m_textures.find(id) != m_textures.end())
    {
        return true;
    }
    else
    {
        MORGAN_DEBUG("TextureID: %s, Texture Path: %s", id, source);
        if(CNgin::renderer() == nullptr)
        {
            MORGAN_DEBUG("RENDERER NULL")
            return false;
        }

        SDL_Texture *texture = nullptr;
        SDL_Surface *surface = IMG_Load(source);
        if (!surface) {
            MORGAN_DEBUG("Cant load IMG")
            return false;
        }

        texture = SDL_CreateTextureFromSurface(CNgin::renderer(), surface);
        SDL_FreeSurface(surface);


        m_textures[id] = texture;
    }


    return true;
}
END_NAMESPACE



