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
            auto cam      = entity.getComponent<CameraComponent>();
            auto sprite   = entity.getComponent<SpriteComponent>();
            auto position = entity.getComponent<PositionComponent>();
            cam->position.setX((position->x + sprite->frameWidth)/ZOOM_FACTOR - cam->size.width/2);
            cam->position.setY((position->y + sprite->frameHeight)/ZOOM_FACTOR - cam->size.height/2);

            int cameraX, cameraY;
            int mapWidth, mapHeight;

            mapWidth  = MapParser::instance()->getMapSize().width;
            mapHeight = MapParser::instance()->getMapSize().height;



            if (cam->position.getX() < 0) {
                cam->position.setX(0);
            }
            if (cam->position.getY() < 0) {
                cam->position.setY(0);
            }
            if (cam->position.getX() > (mapWidth/ZOOM_FACTOR - cam->size.width)) {
                std::cout << "XXXXXX" << std::endl;
                cam->position.setX((mapWidth/ZOOM_FACTOR - cam->size.width));
            }
            if (cam->position.getY() > mapHeight/ZOOM_FACTOR - cam->size.height) {
                cam->position.setY(mapHeight/ZOOM_FACTOR - cam->size.height);
            }

            cameraX = cam->position.getX();
            cameraY = cam->position.getY();

            Game::s_camera = {
                position->x - cameraX,
                position->y - cameraY,
                cam->size.width,
                cam->size.height
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
