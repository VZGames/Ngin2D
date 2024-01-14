#ifndef C_RENDER_SYS_H
#define C_RENDER_SYS_H

#include <CommonDefine.h>
#include "Alias.h"
#include "CEntityRenderer.h"
#include "CTileRenderer.h"

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
    static SDL_Renderer     *s_renderer;
    SDL_Window              *m_window;
    CThreadPool             *m_pool;
    CEntityRenderer         m_entity_renderer;
    CTileRenderer           m_tile_renderer;
    std::vector<ARenderer*> m_renderer;
    std::vector<void*>      m_items;

private:
    CRenderSys();
    ~CRenderSys();
    static CRenderSys *s_instance;
public:
    static CRenderSys *instance();
    static SDL_Renderer* renderer();
    bool isReady();
    bool openWindow(_Title, _Width&, _Height&);
    bool createRenderer();
    void addItem(ABase* item);
    void clearItems();
    void draw();
    void beginDraw();
    void endDraw();
    bool destroyWindow();
    bool destroyRenderer();
};
END_NAMESPACE

#endif // C_RENDER_SYS_H
