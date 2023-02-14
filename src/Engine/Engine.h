#ifndef ENGINE_H
#define ENGINE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_net.h"
#include "SDL2/SDL_ttf.h"

#include "../GameMaps/GameMaps.h"

class Engine
{

public:
    static Engine *instance();
    ~Engine();

    bool init_game(const char *title);
    void loop_game();
    void update_game();
    void render_game();
    void release_resource();
    void quit_game();

    static SDL_Renderer *s_renderer;


private:
    Engine();
    static Engine *s_instance;
    static bool s_gameRunning;

    void handle_events();

    SDL_Window *ptr_window;


    GameMaps *gameMap;

};

#endif // ENGINE_H
