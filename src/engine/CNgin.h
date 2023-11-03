#ifndef CNGIN_H
#define CNGIN_H

#include "CommonDefine.h"
#include "Alias.h"

BEGIN_NAMESPACE(GameNgin)
class CWorld;
class CNgin
{
private:
    CNgin();
    static bool  s_running;
    static CNgin *s_instance;
    SDL_Renderer *m_renderer;
    SDL_Window   *m_window;
    CWorld       *m_world;

    int          m_win_width;
    int          m_win_height;

public:
    static CNgin *instance();
    static bool running();
    static void setRunning(bool);
    bool initialize(Title, Width, Height, CWorld*);
    void loop();
    void clean();
    void quit();

private:
    void render();
    void update(float);
    void handle_events();
};
END_NAMESPACE

#endif // CNGIN_H
