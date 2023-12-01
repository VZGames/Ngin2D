#ifndef CRENDERSYS_H
#define CRENDERSYS_H

#include "CommonDefine.h"
#include "Alias.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class CRenderSys
{
private:
    static SDL_Renderer     *s_renderer;
    SDL_Window              *m_window;

private:
    CRenderSys();
    static CRenderSys *s_instance;
public:
    static CRenderSys *instance();
    static SDL_Renderer* renderer();

    bool openWindow(_Title, _Width&, _Height&);
    bool initRenderer();
    void drawEntity(CEntity*);
    void beginDraw();
    void endDraw();
    bool destroyWindow();
    bool destroyRenderer();
};
END_NAMESPACE

#endif // CRENDERSYS_H
