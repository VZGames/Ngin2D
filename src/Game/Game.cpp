#include "Game.h"
#include "../Defines/Defines.h"
#include "../GameMaps/GameMaps.h"
#include "../Graphics/Graphics.h"
#include "../Event/Events.h"
#include "../Scene/Scene.h"

int g_width, g_height;
namespace ngin2D {
bool Game::s_gameRunning          = false;
Game *Game::s_instance            = nullptr;
SDL_Event Game::s_event;
SDL_Rect Game::s_camera;

Game::Game(): ptr_window(nullptr), ptr_renderer(nullptr)
{
}

Game *Game::instance()
{
    return s_instance = (s_instance == nullptr)? new Game(): s_instance;
}

Game::~Game()
{
    SDL_free(ptr_window);
    SDL_free(ptr_renderer);
}

bool Game::InitGame(const char *title)
{
    printf("Game Init\n");
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

    SDL_GetWindowSize(ptr_window, &g_width, &g_height);


    // [2] init renderer
    ptr_renderer = SDL_CreateRenderer(ptr_window, -1, SDL_RENDERER_ACCELERATED);
    if (ptr_renderer == nullptr)
    {
        printf("Could not create renderer: %s\n\n", SDL_GetError());
        return 0;
    }

    // [3] Select the color for drawing.
    SDL_SetRenderDrawColor(ptr_renderer, 255, 255, 255, 255);

    SDL_RenderSetScale(ptr_renderer, ZOOM_FACTOR, ZOOM_FACTOR);

    Scene::instance()->init();

    s_gameRunning = true;

    return 1;
}

void Game::Loop()
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
        update_game(deltaTime);
        render_game();

        if (deltaTime < frameDelay)
        {
            SDL_Delay(frameDelay - deltaTime);
        }
    }
}

void Game::update_game(float dt)
{
    GameMaps::instance()->update();
    Scene::instance()->update(dt);
}

void Game::render_game()
{
    SDL_RenderClear(ptr_renderer);
    // render objects
    GameMaps::instance()->draw();
    Scene::instance()->render();

    SDL_RenderPresent(ptr_renderer);
}

void Game::Clean()
{
    printf("Game Release Resource\n");
    GameMaps::instance()->clean();
    TextureManager::instance()->clean();
    // Close and destroy the window and the renderer
    SDL_DestroyWindow(ptr_window);
    SDL_DestroyRenderer(ptr_renderer);
}

void Game::Quit()
{
    printf("Game Quit\n");
    SDL_Quit();
    IMG_Quit();
}


void Game::handle_events()
{
    KeyEvent::instance()->listen();
    Scene::instance()->handleEvents();
}
}

