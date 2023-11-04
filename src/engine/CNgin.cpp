#include "CNgin.h"
#include "Logger/LoggerDefines.h"
#include "CKeyEvent.h"
//#include "CSceneManager.h"
#include "CWorld.h"

BEGIN_NAMESPACE(GameNgin)
CNgin *CNgin::s_instance = nullptr;
SDL_Renderer  *CNgin::s_renderer = nullptr;
bool  CNgin::s_running = false;

CNgin::CNgin()
{

}

CNgin *CNgin::instance()
{
    return s_instance = (s_instance == nullptr)? new CNgin(): s_instance;
}

bool CNgin::running()
{
    return s_running;
}

void CNgin::setRunning(bool running)
{
    s_running = running;
}

SDL_Renderer* CNgin::renderer()
{
    return s_renderer;
}

bool CNgin::initialize(Title title, Width width, Height height, CWorld *world)
{
    MORGAN_DEBUG("Game Init");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        MORGAN_DEBUG("Unable to initialize SDL: %s", SDL_GetError());

        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
    {
        MORGAN_DEBUG("Unable to initialize SDL Image: %s", SDL_GetError());
        return false;
    }

    // [1] init SDL and create the Game Window
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    UNUSED(window_flags)

    m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);

    if (m_window == nullptr)
    {
        // In the case that the window could not be made...
        MORGAN_DEBUG("Could not create window: %s", SDL_GetError());

        return false;
    }


    SDL_GetWindowSize(m_window, &m_win_width, &m_win_height);

    MORGAN_DEBUG("Window size: %d, %d", width, height);

    // [2] init renderer
    s_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (s_renderer == nullptr)
    {
        MORGAN_DEBUG("Could not create renderer: %s", SDL_GetError());
        return false;
    }

    // [3] Select the color for drawing.
    SDL_SetRenderDrawColor(s_renderer, 255, 255, 255, 255);

    // [4] start game ngin
    s_running = true;

    // [5] init the world
    m_world  = world;
    if(m_world == nullptr)
    {
        MORGAN_DEBUG("Could not create World");

        return false;
    }

    m_world->init();

    return true;
}

void CNgin::loop()
{
    const int frameDelay = 1000 / 60;

    // time between 2 frames
    float deltaTime = 0.0f;

    // time at start
    Uint32 lastTime = SDL_GetTicks();

    while (s_running) {

        // current time
        Uint32 currentTime = SDL_GetTicks();

        // calculate deltatime
        deltaTime = (float)(currentTime - lastTime)/1000.0f;

        // update lastTime
        lastTime = currentTime;

        // [game logic]
        {
            handle_events();
            update(deltaTime);
            render();
        }
        // [game logic]

        if (deltaTime < frameDelay)
        {
            SDL_Delay(frameDelay - deltaTime);
        }
    }
}


void CNgin::clean()
{
    MORGAN_DEBUG("Game Release Resource");

    // Close and destroy the window and the renderer
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(s_renderer);
}

void CNgin::quit()
{

    SDL_Quit();
    IMG_Quit();
    MORGAN_DEBUG("Game Quit");
}

void CNgin::render()
{
    SDL_RenderClear(s_renderer);
    m_world->render();
    SDL_RenderPresent(s_renderer);
}

void CNgin::update(float dt)
{
    m_world->update(dt);
}
void CNgin::handle_events()
{
    CKeyEvent::instance()->listen();
}
END_NAMESPACE






