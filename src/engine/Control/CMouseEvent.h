#ifndef CMOUSEEVENT_H
#define CMOUSEEVENT_H

#include <CommonDefine.h>
#include <CommonEnums.h>
#include "AEvent.h"

BEGIN_NAMESPACE(engine)
class CMouseEvent : public AEvent
{
private:
    CMouseEvent();
    ~CMouseEvent();
    static CMouseEvent *s_instance;
    std::map<E_MOUSE_EVENT, std::function<void(void)>> m_callback_funcs;
    SDL_Surface *m_surface;
    SDL_Surface *m_newSurface;
    SDL_Cursor *m_cursor;
    SDL_Rect m_cursor_rect;

    void quit();
    void pressed();
    void released();
    void wheel();
    void windowEvent();

public:
    static CMouseEvent *instance();

    template <typename _Func,
             typename... _Args,
             typename _Ret = std::invoke_result_t<_Func, _Args...>>
    void registerMouse(E_MOUSE_EVENT flag, _Func &&fn, _Args &&...args)
    {
        if (m_callback_funcs.find(flag) != m_callback_funcs.end())
        {
            return;
        }

        /* wrapper for no arguments */
        auto task = std::bind(std::forward<_Func>(fn), std::forward<_Args>(args)...);

        // Wrap packaged task into void function
        std::function<void()> wrapper_func = [task]()
        {
            task();
        };

        // Add the function to the map
        m_callback_funcs[flag] = wrapper_func;
    }

public:
    virtual void processEvents(CEventDispatcher *) override;
};
END_NAMESPACE

#endif // CMOUSEEVENT_H
