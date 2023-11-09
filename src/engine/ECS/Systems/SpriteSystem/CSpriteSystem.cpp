#include "CSpriteSystem.h"
#include "LoggerDefines.h"
#include "CTexture2DManager.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SSpriteComponent.h"

BEGIN_NAMESPACE(engine)
CSpriteSystem::CSpriteSystem()
{}

void CSpriteSystem::init()
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

void CSpriteSystem::update(float dt)
{
    UNUSED(dt);
    // do update for each entity
    auto fn = [](CEntity* entity){
        bool hasPosition = entity->hasComponent<SPositionComponent>();
        bool hasSpriteSheet = entity->hasComponent<SSpriteComponent>();
        if((hasPosition && hasSpriteSheet))
        {
            auto sprite = entity->getComponent<SSpriteComponent>();
            sprite->col = (SDL_GetTicks() / sprite->frameSpeed) % sprite->frameCount;
        }
    };
    CWorld::forEachEntities(fn);
}

END_NAMESPACE


