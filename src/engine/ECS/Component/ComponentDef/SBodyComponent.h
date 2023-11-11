#ifndef SBODYCOMPONENT_H
#define SBODYCOMPONENT_H

#include "CommonDefine.h"
#include "CComponent.h"
#include "CWorld.h"

BEGIN_NAMESPACE(engine)
struct SBodyComponent: public CComponent
{
    SBodyComponent(float x, float y, b2BodyType type): CComponent(__FUNCTION__)
    {
        define.type = type;
        define.position.Set(x, y);

        itself = CWorld::instance()->CreateBody(&define);
    }

    template<typename ...TArgs>
    void createFixture(TArgs...args)
    {
        itself->CreateFixture(std::forward<TArgs>(args)...);
    }

    b2BodyDef define;
    b2Body    *itself = nullptr;

};
END_NAMESPACE

#endif // SBODYCOMPONENT_H
