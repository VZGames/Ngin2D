#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include <iostream>
#include "ECS/Systems/ISystem.h"
#include "ECS/Components/Components.h"
#include "ECS/Entity/EntityManager.h"
#include "Math/math2D.h"
#include "GameMaps/MapParser.h"
#include "Math/Shape/IShape.h"
#include "Math/Shape/Ellipse/Ellipse.h"

namespace ngin2D {
class CollisionSystem: public ISystem
{

public:
    CollisionSystem();
    // ISystem interface
public:
    virtual void update(float dt) override;

private:
    bool MapCollision(Entity *entity);
    std::vector<IShape*> CollisionBlocks;
};
}

#endif // COLLISIONSYSTEM_H
