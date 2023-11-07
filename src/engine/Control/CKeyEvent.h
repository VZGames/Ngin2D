#ifndef CKEYEVENT_H
#define CKEYEVENT_H

#include "CommonDefine.h"
#include "LoggerDefines.h"
#include <SDL2/SDL_events.h>

BEGIN_NAMESPACE(Ngin)
class CKeyEvent
{
private:
    CKeyEvent();
    static CKeyEvent                                            *s_instance;
    const Uint8                                                 *m_state;
    bool                                                        m_released{true};
    bool                                                        m_pressed{false};
    SDL_Event                                                   m_event;
    std::unordered_map<SDL_Scancode, std::function<void(void)>> m_inputs;

public:
    static CKeyEvent *instance();
    void listen();

    bool sendEvent(SDL_Scancode);

    CKeyEvent *registerKeyInput(SDL_Scancode, std::function<void(void)>);

    template<typename ...TArgs>
    void handleEvent(SDL_Scancode numkey, TArgs ...args) const
    {
        try
        {
            auto fn = [&](){
                m_inputs.at(numkey)(std::forward<TArgs>(args)...);
            };
            std::thread(fn).join();
        } catch (...)
        {
            MORGAN_DEBUG("This key has no defined behavior ")
        }
    }

    bool isReleased() const;
    bool isPressed() const;

};
END_NAMESPACE
#endif // CKEYEVENT_H
