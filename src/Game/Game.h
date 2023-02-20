#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game
{

public:
    static Game *instance();
    ~Game();

    bool InitGame(const char *title);
    void Loop();
    void Clean();
    void Quit();

    SDL_Renderer *getRenderer()
    {
        return ptr_renderer;
    }

    static bool s_gameRunning;


private:
    Game();
    static Game *s_instance;
    void update_game();
    void render_game();
    void handle_events();

    SDL_Renderer *ptr_renderer;
    SDL_Window *ptr_window;
};

#endif // GAME_H
