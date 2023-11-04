#ifndef CKEYEVENT_H
#define CKEYEVENT_H

#include "CommonDefine.h"
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
    std::unordered_map<SDL_Scancode, std::function<void(void)>> inputs;
public:
    static CKeyEvent *instance();
    void listen();

    bool sendEvent(SDL_Scancode);
    void registerEvent(SDL_Scancode, std::function<void(void)>&);
    const SDL_Event &getEvent() const;

    bool isReleased() const;
    bool isPressed() const;

};
END_NAMESPACE
#endif // CKEYEVENT_H
