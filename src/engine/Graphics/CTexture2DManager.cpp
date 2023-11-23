#include "CTexture2DManager.h"
#include "LoggerDefines.h"
#include "CNgin.h"
#include "CCamera.h"

BEGIN_NAMESPACE(engine)
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
    UNUSED(data)
}

void CTexture2DManager::drawTile(TextureID id, Point2DF pos, TileWidth w, TileHeight h, TileRow r, TileCol c, Angle angle, SDL_RendererFlip flip)
{
    int frameX = w  * c;
    int frameY = h  * r;

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

void CTexture2DManager::drawFrame(TextureID id, Point2DF pos, FrameWidth w, FrameHeight h, FrameRow r, FrameCol c, Angle angle, SDL_RendererFlip flip)
{

    auto fn = [&]()
    {
        LOCK_GUARD(m_mutex);
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

        SDL_RenderDrawRectF(CNgin::renderer(), &destRect);
        SDL_RenderCopyExF(CNgin::renderer(), m_textures[id], &srcRect, &destRect, angle, NULL, flip);
    };

    std::thread(fn).join();
}

bool CTexture2DManager::loadTexture(TextureID id, TextureSource source)
{

    if(m_textures.find(id) != m_textures.end())
    {
        return true;
    }
    else
    {
        DBG("TextureID: %s, Texture Path: %s", id, source);
        if(CNgin::renderer() == nullptr)
        {
            DBG("RENDERER NULL")
            return false;
        }

        SDL_Texture *texture = nullptr;
        SDL_Surface *surface = IMG_Load(source);
        if (!surface) {
            DBG("Cant load IMG")
            return false;
        }

        texture = SDL_CreateTextureFromSurface(CNgin::renderer(), surface);
        SDL_FreeSurface(surface);


        m_textures[id] = texture;
    }


    return true;
}
END_NAMESPACE



