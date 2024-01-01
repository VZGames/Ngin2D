#ifndef CKEYEVENT_H
#define CKEYEVENT_H

#include <future>
#include <type_traits>
#include <CommonDefine.h>
#include <LoggerDefines.h>
#include "AEvent.h"

BEGIN_NAMESPACE(engine)
class CKeyEvent: public AEvent
{
private:
    CKeyEvent();
    static CKeyEvent                                            *s_instance;
    const Uint8                                                 *m_state;
    std::map<uint32_t, std::function<void(void)>>               m_inputs;

private:
    template <typename _Func,
             typename... _Args,
             typename _Ret = std::invoke_result_t<_Func, _Args...>>
    void pushKeyInput(uint32_t code, _Func&& fn, _Args&&... args)
    {
        if (m_inputs.find(code) != m_inputs.end()) {
            return;
        }

        auto task = std::bind(std::forward<_Func>(fn), std::forward<_Args>(args)...);

        // Wrap packaged task into void function
        std::function<void()> wrapper_func = [task]() {
            task();
        };

        // Add the function to the map
        m_inputs[code] = wrapper_func;
    }
    void keyDown();
    void keyUp();

public:
    static CKeyEvent *instance();

    bool sendEvent(uint32_t);

    template<typename _Func,  typename ..._Args>
    void registerKey(SDL_Scancode code, _Func&& fn, _Args&&... args)
    {
        pushKeyInput(code, fn, args...);
    };

    template<typename _Func,  typename ..._Args>
    void registerKey(SDL_EventType type, _Func&& fn, _Args&&... args)
    {
        pushKeyInput(type, fn, args...);
    };

public:
    virtual void processEvents(CEventDispatcher*) override;
};
END_NAMESPACE
#endif // CKEYEVENT_H
