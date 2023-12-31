#include "CSpriteSystem.h"
#include "LoggerDefines.h"
#include "CTexture2DManager.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SSpriteComponent.h"
#include <SDL2/SDL_timer.h>

BEGIN_NAMESPACE(engine)
CSpriteSystem::CSpriteSystem()
{}

void CSpriteSystem::init(CEntity *entity)
{
    auto sprite = entity->getComponent<SSpriteComponent>();
    if(sprite)
    {
        CTexture2DManager::instance()->loadTexture(sprite->textureId, sprite->source);
    }
}

void CSpriteSystem::update(CEntity *entity, float dt)
{
    UNUSED(dt);
    bool position   = entity->getComponent<SPositionComponent>();
    auto sprite     = entity->getComponent<SSpriteComponent>();
    if((position && sprite))
    {
        sprite->col =  (SDL_GetTicks()/ sprite->frameSpeed) % sprite->frameCount;
    }
}

END_NAMESPACE


