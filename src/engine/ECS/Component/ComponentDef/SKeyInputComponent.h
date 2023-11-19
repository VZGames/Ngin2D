#ifndef SKEYINPUTCOMPONENT_H
#define SKEYINPUTCOMPONENT_H

#include "CommonDefine.h"
#include "CComponent.h"
#include "CKeyEvent.h"

BEGIN_NAMESPACE(engine)
struct SKeyInputComponent: public CComponent
{
    SKeyInputComponent(): CComponent(__FUNCTION__)
    {
    }

    template<typename ..._Keys>
    void registerKey(_Keys&&...keys)
    {
        (m_keys.push_back(std::forward<_Keys>(keys)), ...);
    }

    void listen()
    {
        for(uint32_t key: m_keys)
        {
            CKeyEvent::instance()->sendEvent(key);
        }
    }

private:
    std::vector<uint32_t> m_keys;
};
END_NAMESPACE

#endif // SKEYINPUTCOMPONENT_H
