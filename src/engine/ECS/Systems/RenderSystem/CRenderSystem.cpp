#include "CRenderSystem.h"
#include "LoggerDefines.h"
#include "CTexture2DManager.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SSpriteComponent.h"

BEGIN_NAMESPACE(Ngin)
CRenderSystem::CRenderSystem()
{}

void CRenderSystem::init()
{
    auto fn = [](CEntity* entity){
        bool hasSpriteSheet = entity->hasComponent<SSpriteComponent>();
        if(hasSpriteSheet)
        {
            auto sprite = entity->getComponent<SSpriteComponent>();
            CTexture2DManager::instance()->loadTexture(sprite->textureId, sprite->source);
        }
    };
    CWorld::forEachEntities(fn);
}

void CRenderSystem::update(float dt)
{
    UNUSED(dt);
    // do update for each entity
    auto fn = [](CEntity* entity){
        bool hasPosition = entity->hasComponent<SPositionComponent>();
        bool hasSpriteSheet = entity->hasComponent<SSpriteComponent>();
        if(!(hasPosition && hasSpriteSheet)) return;
        auto sprite = entity->getComponent<SSpriteComponent>();
        sprite->col = (SDL_GetTicks() / sprite->frameSpeed) % sprite->frameCount;
    };
    CWorld::forEachEntities(fn);
}

void CRenderSystem::render()
{
    //     do update for each entity
    auto fn = [](CEntity* entity){
        bool hasPosition = entity->hasComponent<SPositionComponent>();
        bool hasSpriteSheet = entity->hasComponent<SSpriteComponent>();
        if(hasPosition && hasSpriteSheet)
        {
            auto sprite = entity->getComponent<SSpriteComponent>();
            auto position = entity->getComponent<SPositionComponent>();
            CTexture2DManager::instance()->drawFrame(
                sprite->textureId,
                Point2DF(position->x,
                         position->y),
                sprite->frameWidth,
                sprite->frameHeight,
                sprite->row,
                sprite->col
                );
        }
    };
    CWorld::forEachEntities(fn);

}
END_NAMESPACE


