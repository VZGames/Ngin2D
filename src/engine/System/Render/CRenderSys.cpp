#include "Render/CRenderSys.h"
#include "CEntity.h"
#include "Camera/CCameraSys.h"
#include "CTexture2DManager.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SBoxComponent.h"
#include "ComponentDef/SCameraComponent.h"

BEGIN_NAMESPACE(engine)
SDL_Renderer  *CRenderSys::s_renderer = nullptr;
CRenderSys *CRenderSys::s_instance = nullptr;
CRenderSys::CRenderSys()
{

}

CRenderSys *CRenderSys::instance()
{
    return s_instance = (s_instance == nullptr)? new CRenderSys(): s_instance;
}

SDL_Renderer *CRenderSys::renderer()
{
    return s_renderer;
}

bool CRenderSys::isReady()
{
    DBG("Game Init");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        DBG("Unable to initialize SDL: %s", SDL_GetError());

        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
    {
        DBG("Unable to initialize SDL Image: %s", SDL_GetError());
        return false;
    }

    return true;
}

bool CRenderSys::openWindow(_Title title, _Width &width, _Height &height)
{
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    UNUSED(window_flags)

    m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);

    if (m_window == nullptr)
    {
        // In the case that the window could not be made...
        DBG("Could not create window: %s", SDL_GetError());

        return false;
    }

    DBG("Window size: %d, %d", width, height);
    return true;
}

bool CRenderSys::createRenderer()
{
    s_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (s_renderer == nullptr)
    {
        DBG("Could not create renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void CRenderSys::drawEntity(CEntity *entity)
{
    Offset *offset = CCameraSys::instance()->offset();
    float scale = CCameraSys::instance()->scale();

    auto sprite = entity->getComponent<SSpriteComponent>();
    auto position = entity->getComponent<SPositionComponent>();
    auto box = entity->getComponent<SBoxComponent>();

    if((position && sprite))
    {
        float x = position->x - offset->x;
        float y = position->y - offset->y;

        CTexture2DManager::instance()->drawFrame(
            sprite->textureId,
            Point2DF(x, y),
            sprite->frameWidth,
            sprite->frameHeight,
            sprite->row,
            sprite->col,
            scale);

        CTexture2DManager::instance()->drawRect(Point2DF(x, y),
                                                sprite->frameWidth,
                                                sprite->frameHeight,
                                                scale);

        if(box)
        {
            CTexture2DManager::instance()->drawPolygon(box->vertices(), std::move(*offset));
        }
    }
}


//void CRenderSys::drawTile(float gX, float gY, STmxTile &&tile)
//{
//    CTexture2DManager::instance()->drawTile(
//        "textureId",
//        Point2DF(gX, gY),
//        tile.width,
//        tile.height,
//        tile.x,
//        tile.y
//        );
//}

void CRenderSys::beginDraw()
{
    SDL_RenderClear(s_renderer);
    SDL_SetRenderDrawColor(s_renderer, 255, 0, 0, 255);
}

void CRenderSys::endDraw()
{
    SDL_SetRenderDrawColor(s_renderer, 255, 255, 255, 255);
    SDL_RenderPresent(s_renderer);
}


bool CRenderSys::destroyWindow()
{
    SDL_DestroyWindow(m_window);
    return m_window == nullptr;

}


bool CRenderSys::destroyRenderer()
{
    SDL_DestroyRenderer(s_renderer);
    return s_renderer == nullptr;
}
END_NAMESPACE

