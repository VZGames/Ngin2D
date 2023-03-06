#include "CameraSystem.h"
#include "../../../Game/Game.h"
#include "SDL2/SDL.h"
#include "../../Components/Components.h"
#include "../../Entity/EntityManager.h"
#include "../../Components/ComponentManager.h"
#include "../../../GameMaps/MapParser.h"

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
            cam->position.setX((position->x + sprite->frameWidth/2 ) - WINDOW_WIDTH/2);
            cam->position.setY((position->y + sprite->frameHeight/2) - WINDOW_HEIGHT/2);

            int cameraX, cameraY;
            int mapWidth, mapHeight;

            cameraX = cam->position.getX();
            cameraY = cam->position.getY();

            mapWidth  = MapParser::instance()->getMapSize().width;
            mapHeight = MapParser::instance()->getMapSize().height;

            printf("Camera X %d, Y %d, Map size W %d, H %d\n", cameraX, cameraY, mapWidth, mapHeight);
            if (cameraX < 0) {
                cameraX = 0;
            }
            if (cameraY < 0) {
                cameraY = 0;
            }
            if (cameraX > mapWidth - WINDOW_WIDTH) {
                cameraX = mapWidth - WINDOW_WIDTH;
            }
            if (cameraY > mapHeight - WINDOW_HEIGHT) {
                cameraY = mapHeight - WINDOW_HEIGHT;
            }

            camera = {cameraX, cameraY, cam->size.width, cam->size.height};

            SDL_RenderSetViewport(Game::instance()->getRenderer(), &camera);

        }
    }
}

}
