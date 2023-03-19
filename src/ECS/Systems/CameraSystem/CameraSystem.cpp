#include "CameraSystem.h"
#include "../../Components/Components.h"
#include "../../Entity/EntityManager.h"
#include "../../Components/ComponentManager.h"
#include "../../../GameMaps/MapParser.h"
#include "../../../Game/Game.h"

namespace ngin2D {

CameraSystem::CameraSystem()
{

}

void CameraSystem::update(float dt)
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<CameraSystem>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<PositionComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.componentBitset);

        if(hasComponent)
        {
            auto camera      = entity.getComponent<CameraComponent>();
            auto sprite   = entity.getComponent<SpriteComponent>();
            auto position = entity.getComponent<PositionComponent>();

            int cameraX, cameraY;

            cameraX = camera->position.getX();
            cameraY = camera->position.getY();

            int mapWidth, mapHeight;
            mapWidth  = MapParser::instance()->getMapSize().width;
            mapHeight = MapParser::instance()->getMapSize().height;


            if (cameraX < 0)
            {
                cameraX = 0;
            }
            if (cameraY < 0)
            {
                cameraY = 0;
            }
            if (cameraX > (mapWidth - camera->size.width) * ZOOM_FACTOR)
            {
                cameraX = (mapWidth - camera->size.width) * ZOOM_FACTOR;
            }
            if (cameraY > (mapHeight - camera->size.height) * ZOOM_FACTOR)
            {
                cameraY = (mapHeight - camera->size.height) * ZOOM_FACTOR;
            }


            Point2DI newPos(cameraX, cameraY);
            camera->position = newPos;


            Game::s_camera = {
                camera->position.getX(),
                camera->position.getY(),
                camera->size.width,
                camera->size.height
            };
//            std::cout << "Camera Position\t" << camera->position;
//            printf("X %d Y %d, W %d H %d\n",
//                   Game::s_camera.x,
//                   Game::s_camera.y,
//                   Game::s_camera.w,
//                   Game::s_camera.h
//                   );
        }
    }
}

}
