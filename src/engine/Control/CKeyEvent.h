#ifndef CKEYEVENT_H
#define CKEYEVENT_H

#include "CommonDefine.h"
#include "LoggerDefines.h"
#include "AEvent.h"

BEGIN_NAMESPACE(engine)
class CKeyEvent: public AEvent
{
private:
    CKeyEvent();
    static CKeyEvent                                            *s_instance;
    const Uint8                                                 *m_state;
    std::map<SDL_Scancode, std::function<void(void)>>           m_inputs;

private:
    void keyDown();
    void keyUp();

public:
    static CKeyEvent *instance();

    bool sendEvent(SDL_Scancode);
    template<typename _Func,  typename ..._Args>
    void registerKey(SDL_Scancode code, _Func&& fn, _Args&&... args)
    {
        if (m_inputs.find(code) != m_inputs.end()) {
            return;
        }

        auto func = std::bind(std::forward<_Func>(fn), std::forward<_Args>(args)...);

        auto task_ptr = std::make_shared<std::packaged_task<void()>>(func);

        // Wrap packaged task into void function
        std::function<void()> wrapper_func = [task_ptr]() {
            (*task_ptr)();
        };

        // Add the function to the map
        m_inputs[code] = func;
    };

public:
    virtual void processEvents(CEventDispatcher*) override;
};
END_NAMESPACE
#endif // CKEYEVENT_H
