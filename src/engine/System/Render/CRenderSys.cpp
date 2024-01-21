#include "Render/CRenderSys.h"
#include "ARenderer.h"
#include "Camera/CCameraSys.h"
#include "ComponentDef/SBoxComponent.h"
#include <ThreadPool/CThreadPool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace engine;
SDL_Renderer  *CRenderSys::s_renderer = nullptr;
CRenderSys *CRenderSys::s_instance = nullptr;
CRenderSys::CRenderSys()
{
    m_renderer.emplace_back(&m_tile_renderer);
    m_renderer.emplace_back(&m_entity_renderer);

    m_pool = new CThreadPool(static_cast<int>(m_renderer.size()));
    m_pool->init();
}

CRenderSys::~CRenderSys()
{
    m_pool->shutdown();
    safeRelease(m_pool);
    DBG("Release Instance CRenderSys At address [%p]", this);
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

    // m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
    // SDL_SetWindowBordered(m_window, SDL_TRUE);
    
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

void CRenderSys::addItem(ABase *item)
{
    m_items.emplace_back(item);
}

void CRenderSys::clearItems()
{
    m_items.clear();
}

void CRenderSys::draw()
{
    float scale = CCameraSys::instance()->scale();
    for(ARenderer *renderer: m_renderer)
    {
        m_pool->submit([&](){
                  for(ABase* item: m_items)
                  {
                      renderer->render(item, scale);
                  }
              }).get();
    }
}

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


