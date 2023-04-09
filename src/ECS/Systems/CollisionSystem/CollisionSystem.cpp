#include "CollisionSystem.h"
#include "Graphics/Graphics.h"
#include "Scene/Scene.h"

namespace ngin2D {

CollisionSystem::CollisionSystem()
{
}

void CollisionSystem::init()
{
    for(auto layer: MapParser::instance()->getObjectLayers())
    {
        for(auto obj: layer.objects)
        {
            IShape *e = nullptr;
            if(obj.shape == std::string("ellipse"))
            {
                e = new Ellipse(obj.width, obj.height, obj.x, obj.y);
            }
            else if(obj.shape == std::string("rectangle"))
            {
                e = new Rectangle(obj.width, obj.height, obj.x, obj.y);
            }

            else if(obj.shape == std::string("polygon"))
            {
                e = new Polygon(obj.x, obj.y, obj.points);
            }

            if(e != nullptr)
            {
                CollisionBlocks.push_back(e);
            }
        }
    }
}

void CollisionSystem::update(float dt)
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<PositionComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<MotionComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<ColliderComponent>(entity.componentBitset);

        if(hasComponent)
        {
            auto motion   = entity.getComponent<MotionComponent>();
            auto pos      = entity.getComponent<PositionComponent>();
            auto box      = entity.getComponent<ColliderComponent>();

            SizeF tileSize = MapParser::instance()->getTileSize();

            bool collided = false;
            collided += MapCollision(&entity);

            if(collided)
            {
                pos->x = box->collidedY? pos->lastX + motion->direction: pos->lastX;
                pos->y = box->collidedX? pos->lastY + motion->direction: pos->lastY;
            }
            else
            {
                box->collidedY = 0;
                box->collidedX = 0;
            }
        }
    }
}

void CollisionSystem::render()
{
    for(auto block: CollisionBlocks)
    {
        if(block->getTypeName() == std::string("ellipse"))
        {
            Ellipse *e = (Ellipse*)block;
            TextureManager::instance()->drawEllipse(e->getCenterI() -= Camera::instance()->position(), e->size().width/2, e->size().height/2);
        }
        else if(block->getTypeName() == std::string("rectangle"))
        {
            Rectangle *e = (Rectangle*)block;
            TextureManager::instance()->drawRectangle(e->getPosition() -= Camera::instance()->position(), e->size().width, e->size().height);
        }
        else if(block->getTypeName() == std::string("polygon"))
        {
            Polygon *e = (Polygon*)block;
            TextureManager::instance()->drawPolygon(e->getPosition(), e->points());
        }
    }
}

bool CollisionSystem::MapCollision(Entity *entity)
{
    auto sprite     = entity->getComponent<SpriteComponent>();
    auto pos        = entity->getComponent<PositionComponent>();
    auto box        = entity->getComponent<ColliderComponent>();

    Point2DF entityI = Point2DF(pos->x + sprite->frameWidth/2,
                                pos->y + sprite->frameHeight/2);
    bool collided   = 0;

    for(auto block: CollisionBlocks)
    {
        IShape *shape = block;
        if(block->getTypeName() == std::string("ellipse"))
        {
            Ellipse *e = (Ellipse*)shape;
            shape = e;
            //            collided += block->contain(Point2DF(pos->x, pos->y));
            //            collided += block->contain(Point2DF(pos->x + sprite->frameWidth, pos->y));
            //            collided += block->contain(Point2DF(pos->x + sprite->frameWidth, pos->y + sprite->frameHeight));
            //            collided += block->contain(Point2DF(pos->x, pos->y + sprite->frameHeight));

            //            if(collided)
            //            {
            //                continue;
            //            }

            if((pos->x <= e->getCenterI().getX() + e->radiusX() &&
                pos->x + sprite->frameWidth >= e->getCenterI().getX() - e->radiusX()) &&
                    (pos->y <= e->getCenterI().getY() + e->radiusY() &&
                     pos->y + sprite->frameHeight >= e->getCenterI().getY() - e->radiusY()))
            {
                collided = 1;
            }
        }
        else if(block->getTypeName() == std::string("rectangle"))
        {
            SDL_FRect entiyBox = {
                pos->x,
                pos->y,
                sprite->frameWidth,
                sprite->frameHeight
            };
            collided += SDL_HasIntersectionF(&block->getRect(), &entiyBox);
        }

        if(collided)
        {
            float distance = block->getCenterI()
                                .distance(Point2DF(pos->x + sprite->frameWidth/2,
                                                   pos->y + sprite->frameHeight/2));

//            printf("%f %f\n", distance- sprite->frameHeight/2, block->getCenterI().distance(block->getPosition()));
//            if(distance - sprite->frameHeight/2 == block->getCenterI().distance(block->getPosition()))
//            {
//                std::cout << "Y\n";
//                box->collidedX = 0;
//                box->collidedY = 1;
//            }
//            else if(distance - sprite->frameWidth/2 == block->getCenterI().distance(block->getPosition()))
//            {
//                std::cout << "X\n";
//                box->collidedX = 1;
//                box->collidedY = 0;
//            }
        }


    }
    return collided;
}

bool CollisionSystem::OtherEntitiesCollision(Entity *entity)
{
    return 0;
}

}
