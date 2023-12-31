#include "CTexture2DManager.h"
#include "LoggerDefines.h"
#include "Render/CRenderSys.h"
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

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

void CTexture2DManager::drawTile(_TextureID id, Point2DF pos, _TileWidthF w, _TileHeightF h, TileRow r, TileCol c, _Scale scale, _Angle angle, SDL_RendererFlip flip)
{
    int frameX = w  * c;
    int frameY = h  * r;

    SDL_Rect srcRect = {frameX, frameY, (int)w, (int)h};
    SDL_FRect destRect = {
        pos.x() * scale,
        pos.y() * scale,
        w * scale,
        h * scale
    };

    SDL_RenderCopyExF(CRenderSys::renderer(), m_textures[id], &srcRect, &destRect, angle, NULL, flip);
}

void CTexture2DManager::drawFrame(_TextureID id, Point2DF pos, _FrameWidthF w, _FrameHeightF h, _FrameRow r, _FrameCol c, _Scale scale, _Angle angle, SDL_RendererFlip flip)
{

    int frameX = w * c;
    int frameY = h * r;
    SDL_Rect srcRect = {frameX, frameY, (int)w, (int)h};
    SDL_FRect destRect = {
        pos.x(),
        pos.y(),
        w * scale,
        h * scale
    };
    SDL_RenderCopyExF(CRenderSys::renderer(), m_textures[id], &srcRect, &destRect, angle, NULL, flip);

}

bool CTexture2DManager::loadTexture(_TextureID id, _TextureSource source)
{

    if(m_textures.find(id) != m_textures.end())
    {
        return true;
    }
    else
    {
        DBG("TextureID: %s, Texture Path: %s", id, source);
        if(CRenderSys::renderer() == nullptr)
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

        texture = SDL_CreateTextureFromSurface(CRenderSys::renderer(), surface);
        SDL_FreeSurface(surface);


        m_textures[id] = texture;
    }


    return true;
}

void CTexture2DManager::drawRect(Point2DF pos, _FrameWidthF w, _FrameHeightF h, _Scale scale)
{
    SDL_FRect destRect = {
        pos.x(),
        pos.y(),
        w * scale,
        h * scale
    };

    SDL_RenderDrawRectF(CRenderSys::renderer(), &destRect);
}
void CTexture2DManager::drawPolygon(std::vector<Vector2D<float>> vertices, Vector2D<float> &&offset)
{
    SDL_FPoint points[vertices.size() + 1];
    int count = static_cast<int>(vertices.size());
    for (int i = 0; i < count; i++)
    {
        points[i] = {(vertices[i].x - offset.x), (vertices[i].y - offset.y)};
    }

    points[vertices.size()] = points[0];


    SDL_RenderDrawLinesF(CRenderSys::renderer(), points, sizeof(points)/sizeof(SDL_FPoint));
}
END_NAMESPACE





