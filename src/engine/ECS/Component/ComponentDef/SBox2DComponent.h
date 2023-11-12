#ifndef SBOX2DCOMPONENT_H
#define SBOX2DCOMPONENT_H

#include "CommonDefine.h"
#include "CComponent.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(engine)
struct SBox2DComponent: public CComponent
{
    SBox2DComponent(float width, float height, std::vector<b2Vec2> vecs): CComponent(__FUNCTION__)
    {
        count = vecs.size();
        vertices = vecs.data();
        shape.Set(vertices, count);
        shape.SetAsBox(width/2.0f, height/2.0f);

        fixtureDef.shape    = &shape;
        fixtureDef.density  = 1.0f;
    }

    b2Vec2         *vertices;
    int32          count = 0;
    b2FixtureDef   fixtureDef;
    b2PolygonShape shape;
};
END_NAMESPACE

#endif // SBOX2DCOMPONENT_H
