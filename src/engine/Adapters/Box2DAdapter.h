#ifndef BOX2DADAPTER_H
#define BOX2DADAPTER_H

#include "CommonDefine.h"
#include "vector2d.h"

BEGIN_NAMESPACE(engine)
b2Vec2 vec2Ftob2Vec2(const Vector2DF &vec)
{
    return b2Vec2(vec.x, vec.y);
}

END_NAMESPACE

#endif // BOX2DADAPTER_H
