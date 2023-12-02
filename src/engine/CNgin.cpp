#include "CNgin.h"
#include "LoggerDefines.h"
#include "CEventDispatcher.h"
#include "CMouseEvent.h"
#include "CKeyEvent.h"
#include "CWorld.h"
#include "CRenderSys.h"

BEGIN_NAMESPACE(engine)
CNgin *CNgin::s_instance = nullptr;
bool  CNgin::s_running = false;
std::mutex CNgin::s_mutex;
uint32_t CNgin::s_win_width = 0;
uint32_t CNgin::s_win_height = 0;
CNgin::CNgin(): m_key_evt_pool(2)
{
}

CNgin::~CNgin()
{
    m_key_evt_pool.shutdown();
}

CNgin *CNgin::instance()
{
    return s_instance = (s_instance == nullptr)? new CNgin(): s_instance;
}

bool CNgin::running()
{
    LOCK_GUARD(s_mutex)
    return s_running;
}

void CNgin::setRunning(bool running)
{
    LOCK_GUARD(s_mutex)
    s_running = running;
}

Size2D<float> CNgin::windowSize()
{
    return Size2D<float>{(float)s_win_width, (float)s_win_height};
}

bool CNgin::initialize(_Title title, _Width width, _Height height, CWorld *world)
{
    if(!CRenderSys::instance()->isReady()) return false;

    // [1] init SDL and create the Game Window
    if(CRenderSys::instance()->openWindow(title, width, height))
    {
        s_win_width = width;
        s_win_height = height;
        // [2] init renderer
        if(!CRenderSys::instance()->createRenderer())
        {
            return false;
        }
    }

    // [3] start game engine
    s_running = true;

    // [4 init the world
    m_world  = world;
    if(m_world == nullptr)
    {
        DBG("Could not create World");

        return false;
    }

    m_world->init();
    m_key_evt_pool.init();

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
    CRenderSys::instance()->destroyWindow();
    CRenderSys::instance()->destroyRenderer();
}

void CNgin::quit()
{

    IMG_Quit();
    SDL_Quit();
    DBG("Game Quit");
}

void CNgin::render()
{
    CRenderSys::instance()->beginDraw();
    m_world->render();
    CRenderSys::instance()->endDraw();

}

void CNgin::update(float dt)
{
    m_world->update(dt);
}
void CNgin::handle_events()
{
    CEventDispatcher::instance()->listen();
    m_key_evt_pool.submit(&CMouseEvent::processEvents, CMouseEvent::instance(), CEventDispatcher::instance()).get();
    m_key_evt_pool.submit(&CKeyEvent::processEvents, CKeyEvent::instance(), CEventDispatcher::instance()).get();
}
END_NAMESPACE












