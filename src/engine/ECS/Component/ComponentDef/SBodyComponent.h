#ifndef SBODYCOMPONENT_H
#define SBODYCOMPONENT_H

#include "CommonDefine.h"
#include "CComponent.h"
#include "CWorld.h"

BEGIN_NAMESPACE(engine)
struct SBodyComponent: public CComponent
{
    SBodyComponent(b2BodyType type): CComponent(__FUNCTION__)
    {
        define.type = type;
        define.position.Set(0.0f, 0.0f);

        itself = CWorld::instance()->CreateBody(&define);
    }

    template<typename ...TArgs>
    void createFixture(TArgs...args)
    {
        itself->CreateFixture(std::forward<TArgs>(args)...);
    }

    void SetTransform(const b2Vec2 &newposition, float angle = 0.0f)
    {
        itself->SetTransform(newposition, angle);
    }

    void SetLinearVelocity(const b2Vec2 &velocity)
    {
        itself->SetLinearVelocity(velocity);
    }

    b2BodyDef define;
    b2Body    *itself = nullptr;

};
END_NAMESPACE

#endif // SBODYCOMPONENT_H
