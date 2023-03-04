#include "RenderSystem.h"
#include "SDL2/SDL.h"
#include "../../Entity/EntityManager.h"
#include "../../Components/Components.h"
#include "../../Components/ComponentManager.h"
#include "../../../Graphics/TextureManager/TextureManager.h"

namespace ngin2D {
RenderSystem::RenderSystem()
{}

void RenderSystem::init()
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.componentBitset);
        if(hasComponent)
        {
            auto sprite = entity.getComponent<SpriteComponent>();
            TextureManager::instance()->loadTexture(sprite->textureId, sprite->source);
        }
    }
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
            TextureManager::instance()->drawFrame(sprite->textureId, position->pos, sprite->frameWidth, sprite->frameHeight, sprite->row, sprite->col);
        }
    }
}
}
