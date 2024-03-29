#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include <iostream>
#include "ECS/Systems/ISystem.h"
#include "ECS/Components/Components.h"
#include "ECS/Entity/EntityManager.h"
#include "Math/math2D.h"
#include "GameMaps/MapParser.h"
#include "Math/Shape/IShape.h"
#include "Math/Shape/Shapes.h"
#include "CollisionManager.h"

namespace ngin2D {
class CollisionSystem: public ISystem
{

public:
    CollisionSystem();
    // ISystem interface
public:
    virtual void init() override;
    virtual void update(float dt) override;
    virtual void render() override;

private:
    bool MapCollision(Entity *entity);
    bool OtherEntitiesCollision(Entity *entity);
    bool testCollision();

    CollisionManager m_collisionManager;
    std::vector<IShape*> CollisionBlocks;
};
}

#endif // COLLISIONSYSTEM_H
