#ifndef CCALLBACKFUNC_H
#define CCALLBACKFUNC_H

#include <tuple>

// Primary template for the callback
template <typename _Func, typename... _Args>
class CCallbackFunc
{
private:
    _Func m_func;
    std::tuple<_Args...> m_arguments;
public:
    CCallbackFunc(_Func fn, _Args ...args)
        :m_func(fn), m_arguments(args...)
    {

    }

    void invoke() {
        m_func(m_arguments);
    }
};

#endif // CCALLBACKFUNC_H
