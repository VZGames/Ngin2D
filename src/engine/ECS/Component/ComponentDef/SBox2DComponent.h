#ifndef SBOX2DCOMPONENT_H
#define SBOX2DCOMPONENT_H

#include "CommonDefine.h"
#include "CComponent.h"

BEGIN_NAMESPACE(engine)
struct SBox2DComponent: public CComponent
{
    SBox2DComponent(float x, float y, std::vector<b2Vec2> vecs): CComponent(__FUNCTION__)
    {
        int32 count = vecs.size();
        b2Vec2 vertices[count];
        std::copy(vecs.begin(), vecs.end(), vertices);
        shape.Set(vertices, count);
        shape.SetAsBox(x, y);

        fixtureDef.shape = &shape;
        fixtureDef.density = 1.0f;
    }

    b2FixtureDef   fixtureDef;
    b2PolygonShape shape;
};
END_NAMESPACE

#endif // SBOX2DCOMPONENT_H
