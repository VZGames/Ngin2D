#ifndef CEVENTDISPATCHER_H
#define CEVENTDISPATCHER_H

#include <CommonDefine.h>
#include <SDL2/SDL_events.h>

BEGIN_NAMESPACE(engine)
class CEventDispatcher
{
private:
    CEventDispatcher();
    static CEventDispatcher *s_instance;

    std::mutex              m_mutex;
    std::queue<SDL_Event>   m_events;
public:
    static CEventDispatcher *instance();

    void listen();

    bool getNextEvent(SDL_Event &);
};
END_NAMESPACE

#endif // CEVENTDISPATCHER_H
