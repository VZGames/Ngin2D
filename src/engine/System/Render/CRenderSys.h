#ifndef C_RENDER_SYS_H
#define C_RENDER_SYS_H

#include <CommonDefine.h>
#include "Alias.h"
#include "CEntityRenderer.h"
#include "CTileRenderer.h"
#include <LoggerDefines.h>

class SDL_Renderer;
class SDL_Window;
class CThreadPool;
BEGIN_NAMESPACE(engine)
class ABase;
class CEntity;
class ARenderer;
class CRenderSys
{
private:
    static SDL_Renderer             *s_renderer;
    SDL_Window                      *m_window;
    CThreadPool                     *m_pool;
    CEntityRenderer                 m_entity_renderer;
    CTileRenderer                   m_tile_renderer;
    std::vector<ARenderer*>         m_renderer;
    std::vector<ABase*>             m_items;

private:
    CRenderSys();
    static CRenderSys *s_instance;
public:
    ~CRenderSys();
    static CRenderSys *instance();
    static SDL_Renderer* renderer();
    bool isReady();
    bool openWindow(_Title, _Width&, _Height&);
    bool createRenderer();
    void addItem(ABase*);
    void clearItems();
    void draw();
    void beginDraw();
    void endDraw();
    bool destroyWindow();
    bool destroyRenderer();
};
END_NAMESPACE

#endif // C_RENDER_SYS_H
