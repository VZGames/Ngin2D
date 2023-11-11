#include "CNgin.h"
#include "Logger/LoggerDefines.h"
#include "CEventDispatcher.h"
#include "CKeyEvent.h"
#include "CMouseEvent.h"
#include "CWorld.h"

BEGIN_NAMESPACE(engine)
CNgin *CNgin::s_instance = nullptr;
SDL_Renderer  *CNgin::s_renderer = nullptr;
bool  CNgin::s_running = false;
std::mutex CNgin::s_mutex;
int CNgin::s_win_width = 0;
int CNgin::s_win_height = 0;
CNgin::CNgin()
{

}

CNgin *CNgin::instance()
{
    return s_instance = (s_instance == nullptr)? new CNgin(): s_instance;
}

bool CNgin::running()
{
    std::lock_guard<std::mutex> lck(s_mutex);
    return s_running;
}

void CNgin::setRunning(bool running)
{
    std::lock_guard<std::mutex> lck(s_mutex);
    s_running = running;
}

SDL_Renderer* CNgin::renderer()
{
    return s_renderer;
}

Size2D<float> CNgin::windowSize()
{
    return Size2D<float>{(float)s_win_width, (float)s_win_height};
}

bool CNgin::initialize(Title title, Width width, Height height, CWorld *world)
{
    DBG("Game Init");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        DBG("Unable to initialize SDL: %s", SDL_GetError());

        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
    {
        DBG("Unable to initialize SDL Image: %s", SDL_GetError());
        return false;
    }

    // [1] init SDL and create the Game Window
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    UNUSED(window_flags)

    m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);

    if (m_window == nullptr)
    {
        // In the case that the window could not be made...
        DBG("Could not create window: %s", SDL_GetError());

        return false;
    }


    SDL_GetWindowSize(m_window, &s_win_width, &s_win_height);

    DBG("Window size: %d, %d", width, height);

    // [2] init renderer
    s_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (s_renderer == nullptr)
    {
        DBG("Could not create renderer: %s", SDL_GetError());
        return false;
    }

    // [3] Select the color for drawing.
    SDL_SetRenderDrawColor(s_renderer, 255, 255, 255, 255);

    // [4] start game engine
    s_running = true;

    // [5] init the world
    m_world  = world;
    if(m_world == nullptr)
    {
        DBG("Could not create World");

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
    DBG("Game Release Resource");

    // Close and destroy the window and the renderer
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(s_renderer);
}

void CNgin::quit()
{

    SDL_Quit();
    IMG_Quit();
    DBG("Game Quit");
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

    CEventDispatcher::instance()->listen();
    std::thread keyEventThread(std::bind(
        &CKeyEvent::processEvents,
        CKeyEvent::instance(),
        CEventDispatcher::instance()));
    std::thread mouseEventThread(std::bind(
        &CMouseEvent::processEvents,
        CMouseEvent::instance(),
        CEventDispatcher::instance()));

    keyEventThread.detach();
    mouseEventThread.detach();
}
END_NAMESPACE










