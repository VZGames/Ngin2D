#include "CameraSystem.h"
#include "ECS/Entity/EntityManager.h"
#include "ECS/Components/Components.h"
#include "GameMaps/MapParser.h"
#include "Game/Game.h"

namespace ngin2D {

CameraSystem::CameraSystem()
{

}

void CameraSystem::update(float dt)
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<CameraSystem>(entity.componentBitset);

        if(hasComponent)
        {
            auto camera   = entity.getComponent<CameraComponent>();

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
            if (cameraX > (mapWidth - camera->size.width))
            {
                cameraX = (mapWidth - camera->size.width);
            }
            if (cameraY > (mapHeight - camera->size.height))
            {
                cameraY = (mapHeight - camera->size.height);
            }


            camera->position = Point2DI(cameraX, cameraY);

            Game::s_camera = {
                camera->position.getX(),
                camera->position.getY(),
                camera->size.width,
                camera->size.height
            };


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
