#include "Engine.h"
#include "../Defines/Defines.h"
#include "../GameMaps/GameMaps.h"
#include "../Graphics/Graphics.h"

bool Engine::s_gameRunning          = false;
Engine *Engine::s_instance          = nullptr;
SDL_Renderer *Engine::s_renderer    = nullptr;


Engine::Engine(): ptr_window(nullptr)
{
}

Engine *Engine::instance()
{
    return s_instance = (s_instance == nullptr)? new Engine(): s_instance;
}

Engine::~Engine()
{
}

bool Engine::init_game(const char *title)
{
    printf("Engine Init\n");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 0;
    }

    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
    {
        printf("Unable to initialize SDL Image: %s\n", SDL_GetError());
        return 0;
    }

    // [1] init SDL and create the Game Window
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    ptr_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, window_flags);


    if (ptr_window == nullptr)
    {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n\n", SDL_GetError());
        return 0;
    }

    // [2] init renderer
    s_renderer = SDL_CreateRenderer(ptr_window, -1, SDL_RENDERER_ACCELERATED);


    if (s_renderer == nullptr)
    {
        return 0;
    }

    tex = TextureManager::instance()->texture_by_id("Water");
    SDL_QueryTexture(tex, NULL, NULL, &destRec.w, &destRec.h);

    // [3] Select the color for drawing.
    SDL_SetRenderDrawColor(s_renderer, 255, 255, 255, 255);


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

        handle_events();
        update_game();
        render_game();

        if (deltaTime < frameDelay)
        {
            SDL_Delay(frameDelay - deltaTime);
        }
    }
}

void Engine::update_game()
{
    GameMaps::instance()->update();
}

void Engine::render_game()
{
    SDL_RenderClear(s_renderer);
    // render objects
    GameMaps::instance()->draw();
    SDL_RenderCopy(s_renderer, tex, NULL, &destRec);
//    TextureManager::instance()->draw("Water", Point2D(200, 200), 16, 16);

    SDL_RenderPresent(s_renderer);
}

void Engine::release_resource()
{
    printf("Engine Release Resource\n");
    GameMaps::instance()->clean();
    TextureManager::instance()->clean();
    // Close and destroy the window and the renderer
    SDL_DestroyWindow(ptr_window);
    SDL_DestroyRenderer(s_renderer);
}

void Engine::quit_game()
{
    printf("Engine Quit\n");
    SDL_Quit();
    IMG_Quit();
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

