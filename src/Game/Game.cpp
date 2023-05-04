#include "Game.h"
#include "Defines/Defines.h"
#include "GameMaps/GameMaps.h"
#include "Graphics/Graphics.h"
#include "Event/Events.h"
#include "World/World.h"
#include "Scene/Scene.h"

int g_width, g_height;
namespace ngin2D {
bool Game::s_gameRunning          = false;
Game *Game::s_instance            = nullptr;
SDL_Event Game::s_event;

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
    LOG_INFO("Game Init");

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        LOG_INFO("Unable to initialize SDL: %s", SDL_GetError());

        return 0;
    }

    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
    {
        LOG_INFO("Unable to initialize SDL Image: %s", SDL_GetError());
        return 0;
    }

    // [1] init SDL and create the Game Window
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    ptr_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);


    if (ptr_window == nullptr)
    {
        // In the case that the window could not be made...
        LOG_INFO("Could not create window: %s", SDL_GetError());

        return 0;
    }

//    SDL_MaximizeWindow(ptr_window);


    SDL_GetWindowSize(ptr_window, &g_width, &g_height);

    LOG_INFO("Window size: %d, %d", g_width, g_height);

    // [2] init renderer
    ptr_renderer = SDL_CreateRenderer(ptr_window, -1, SDL_RENDERER_ACCELERATED);
    if (ptr_renderer == nullptr)
    {
        LOG_INFO("Could not create renderer: %s", SDL_GetError());
        return 0;
    }

    // [3] Select the color for drawing.
    SDL_RenderSetScale(ptr_renderer, ZOOM_FACTOR, ZOOM_FACTOR);
    SDL_SetRenderDrawColor(ptr_renderer, 255, 255, 255, 255);

    b2Vec2 gravity(0.0f, -10.0f);
    World::instance(gravity);

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
//    SDL_RenderDrawRectF(ptr_renderer, &Camera::instance()->viewport());

    SDL_RenderPresent(ptr_renderer);
}

void Game::Clean()
{
    LOG_INFO("Game Release Resource");

    GameMaps::instance()->clean();
    TextureManager::instance()->clean();
    // Close and destroy the window and the renderer
    SDL_DestroyWindow(ptr_window);
    SDL_DestroyRenderer(ptr_renderer);
}

void Game::Quit()
{

    SDL_Quit();
    IMG_Quit();
    LOG_INFO("Game Quit");
}


void Game::handle_events()
{
    KeyEvent::instance()->listen();
    Scene::instance()->handleEvents();
}
}

