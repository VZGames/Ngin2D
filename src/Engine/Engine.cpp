#include "Engine.h"
#include "../Defines/Defines.h"
#include "stdio.h"

Engine *Engine::s_instance = nullptr;
bool Engine::s_gameRunning = false;
SDL_Renderer *Engine::s_renderer = nullptr;


Engine::Engine()
{
    gameMap = new GameMaps();
}

Engine *Engine::instance()
{
    return s_instance = (s_instance == nullptr)? new Engine(): s_instance;
}

Engine::~Engine()
{
    release_resource();
    quit_game();
}

bool Engine::init_game(const char *title)
{
    printf("Engine Init\n");
    // [1] init SDL and create the Game Window
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 0;
    }

    ptr_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);


    if (ptr_window == nullptr)
    {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n\n", SDL_GetError());
    }


    s_renderer = SDL_CreateRenderer(ptr_window, -1, SDL_RENDERER_ACCELERATED);


    if (s_renderer)
    {
        // Select the color for drawing.
        SDL_SetRenderDrawColor(s_renderer, 0, 0, 0, 255);
    }


    s_gameRunning = true;
    return 1;
}

void Engine::loop_game()
{
    const int frameDelay = 1000 / FPS;

    // time between 2 frames
    float deltaTime = 0.0f;

    // time at start
    Uint32 lastTime = SDL_GetTicks();

    while (s_gameRunning) {

        // current time
        Uint32 currentTime = SDL_GetTicks();

        // calculate deltatime
        deltaTime = (float)(currentTime - lastTime)/1000.0f;

        // update lastTime
        lastTime = currentTime;


        if (deltaTime < frameDelay)
        {
            SDL_Delay(frameDelay - deltaTime);
        }

        handle_events();
        update_game();
        render_game();
        SDL_GL_SwapWindow(ptr_window);
    }
}

void Engine::update_game()
{
}

void Engine::render_game()
{
    SDL_RenderClear(s_renderer);
    // render objects
    SDL_RenderPresent(s_renderer);
}

void Engine::release_resource()
{
    printf("Engine Release Resource\n");
    // Close and destroy the window and the renderer
    SDL_DestroyWindow(ptr_window);
    SDL_DestroyRenderer(s_renderer);
}

void Engine::quit_game()
{
    printf("Engine Quit\n");
    SDL_Quit();
}


void Engine::handle_events()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
        {
            s_gameRunning = false;
        }
    }
}

