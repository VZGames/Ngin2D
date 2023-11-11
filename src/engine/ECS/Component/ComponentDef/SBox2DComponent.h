#ifndef SBOX2DCOMPONENT_H
#define SBOX2DCOMPONENT_H

#include "CommonDefine.h"
#include "CComponent.h"
//#include "CWorld.h"
#include <Box2D/box2d.h>

BEGIN_NAMESPACE(engine)
struct SBox2DComponent: public CComponent
{
    SBox2DComponent(uint32_t type, std::vector<b2Vec2> vecs): CComponent(__FUNCTION__)
    {
        int32 count = vecs.size();
        b2Vec2 vertices[count];
        std::copy(vecs.begin(), vecs.end(), vertices);

        if(((uint32_t)b2Shape::Type::e_polygon & type) == (uint32_t)b2Shape::Type::e_polygon)
        {
            b2PolygonShape *polygon = new b2PolygonShape();
            polygon->Set(vertices, count);
            shape = polygon;
        }
        else if(((uint32_t)b2Shape::Type::e_chain & type) == (uint32_t)b2Shape::Type::e_chain)
        {
            b2ChainShape *chain = new b2ChainShape();
            chain->CreateLoop(vertices, count);
            shape = chain;
        }
    }

    b2Shape *shape = nullptr;
};
END_NAMESPACE

#endif // SBOX2DCOMPONENT_H
