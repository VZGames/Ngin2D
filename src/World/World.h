#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <Box2D/box2d.h>
#include "Utils/Utils.h"

namespace ngin2D {
class World: public b2World
{
public:
    static World *instance(const b2Vec2& gravity);

    inline void appendBody(b2Body* body)
    {
        m_bodies.push_back(body);
    }

private:
    explicit World(const b2Vec2 &gravity);
    static World *s_instance;
    std::vector<b2Body*> m_bodies;

};
}

#endif // WORLD_H
