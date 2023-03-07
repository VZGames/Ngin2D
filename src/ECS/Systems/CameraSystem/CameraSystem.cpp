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
            cam->position.setX((position->x + sprite->frameWidth/2) - cam->size.width/2);
            cam->position.setY((position->y + sprite->frameHeight/2) - cam->size.height/2);

            int cameraX, cameraY;
            int mapWidth, mapHeight;

            mapWidth  = MapParser::instance()->getMapSize().width;
            mapHeight = MapParser::instance()->getMapSize().height;

            if (cam->position.getX() <= 0) {
                cam->position.setX(0);
            }
            if (cam->position.getY() <= 0) {
                cam->position.setY(0);
            }
            if (cam->position.getX() > mapWidth - cam->size.width) {
                cam->position.setX(mapWidth - cam->size.width);
            }
            if (cam->position.getY() > mapHeight - cam->size.height) {
                cam->position.setY(mapHeight - cam->size.height);
            }

            cameraX = cam->position.getX();
            cameraY = cam->position.getY();

//            position->x = cameraX + cam->size.width/2;
//            position->y = cameraY + cam->size.height/2;



            printf("Camera X %d, Y %d, Map size W %d, H %d\n", cameraX, cameraY, mapWidth, mapHeight);

            Game::s_camera = {position->x - cameraX, position->y - cameraY, cam->size.width, cam->size.height};
        }
    }
}

}
