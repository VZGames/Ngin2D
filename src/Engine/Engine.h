#ifndef ENGINE_H
#define ENGINE_H
#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Engine
{

public:
    static Engine *instance();
    ~Engine();

    bool init_game(const char *title);
    void loop_game();
    void release_resource();
    void quit_game();

    static SDL_Renderer *s_renderer;
    static bool s_gameRunning;


private:
    Engine();
    static Engine *s_instance;
    void update_game();
    void render_game();
    void handle_events();

    SDL_Window *ptr_window;

    SDL_Texture *tex;
    SDL_Rect srcRec,destRec;
};

#endif // ENGINE_H
