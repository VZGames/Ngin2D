#include "RenderSystem.h"
#include "ECS/Entity/EntityManager.h"
#include "ECS/Components/Components.h"
#include "Graphics/TextureManager/TextureManager.h"
#include "Scene/Camera/Camera.h"

namespace ngin2D {
RenderSystem::RenderSystem()
{}

void RenderSystem::init()
{
}

void RenderSystem::update(float dt)
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<HealthComponent>(entity.componentBitset);
        if(hasComponent)
        {
           auto sprite = entity.getComponent<SpriteComponent>();
           sprite->col = (SDL_GetTicks() / sprite->frameSpeed) % sprite->frameCount;
        }
    }
}

void RenderSystem::render()
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<PositionComponent>(entity.componentBitset);

        if(hasComponent)
        {
            auto sprite = entity.getComponent<SpriteComponent>();
            auto position = entity.getComponent<PositionComponent>();

            TextureManager::instance()->loadTexture(sprite->textureId, sprite->source);

            bool hasCamera = ComponentManager::instance()->hasComponentType<CameraComponent>(entity.componentBitset);
            int cameraX = 0;
            int cameraY = 0;
            if(hasCamera)
            {
                auto camPos = Camera::instance()->position();
                cameraX = camPos.getX();
                cameraY = camPos.getY();
            }

            TextureManager::instance()->drawFrame(
                        sprite->textureId,
                        Point2DI(position->x - cameraX,
                                 position->y - cameraY),
                        sprite->frameWidth,
                        sprite->frameHeight,
                        sprite->row,
                        sprite->col);
        }
    }
}
}

