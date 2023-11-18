#ifndef CMOUSEEVENT_H
#define CMOUSEEVENT_H

#include "CommonDefine.h"
#include "CommonEnums.h"
#include "AEvent.h"

BEGIN_NAMESPACE(engine)
class CMouseEvent: public AEvent
{
private:
    CMouseEvent();
    static CMouseEvent *s_instance;
    std::map<E_MOUSE_EVENT, std::function<void(void)>>           m_callback_funcs;

    void pressed(int x, int y);
    void released(int x, int y);

public:
    static CMouseEvent *instance();

    template<typename _Func,  typename ..._Args>
    void registerMouse(E_MOUSE_EVENT flag, _Func&& fn, _Args&&... args)
    {
        if (m_callback_funcs.find(flag) != m_callback_funcs.end()) {
            return;
        }

        /* The return type of task `F` */
        using return_type = std::result_of_t<_Func(_Args...)>;

        /* wrapper for no arguments */
        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<_Func>(fn), std::forward<_Args>(args)...));

        // Wrap packaged task into void function
        std::function<void()> wrapper_func = [task]() {
            (*task)();
        };

        // Add the function to the map
        m_callback_funcs[flag] = wrapper_func;

    }

public:
    virtual void processEvents(CEventDispatcher*) override;
};
END_NAMESPACE

#endif // CMOUSEEVENT_H
