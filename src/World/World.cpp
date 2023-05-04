#include "World.h"

namespace ngin2D {
World *World::s_instance = nullptr;
World *World::instance(const b2Vec2& gravity)
{
    return s_instance = (s_instance == nullptr)? new World(gravity): s_instance;
}

World::World(const b2Vec2 &gravity) : b2World(gravity)
{}

}
