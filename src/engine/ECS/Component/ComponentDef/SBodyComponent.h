#ifndef SBODYCOMPONENT_H
#define SBODYCOMPONENT_H

#include "CommonDefine.h"
#include "CComponent.h"
#include "CWorld.h"
#include <Box2D/box2d.h>


BEGIN_NAMESPACE(engine)
struct SBodyComponent: public CComponent
{
    SBodyComponent(b2BodyType type, b2Shape *shape): CComponent(__FUNCTION__)
    {
        define.type = type;
        define.position.Set(0, 0);

        fixtureDef.shape = shape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        itself->CreateFixture(&fixtureDef);
    }
    b2BodyDef define;
    b2FixtureDef fixtureDef;
    b2Body    *itself = CWorld::instance()->CreateBody(&define);;

};
END_NAMESPACE

#endif // SBODYCOMPONENT_H
