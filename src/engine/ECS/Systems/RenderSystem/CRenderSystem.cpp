#include "CRenderSystem.h"
#include "LoggerDefines.h"
#include "CTexture2DManager.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SSpriteComponent.h"

BEGIN_NAMESPACE(GameNgin)
CRenderSystem::CRenderSystem()
{}

void CRenderSystem::update(float dt)
{
    UNUSED(dt);
}

void CRenderSystem::update(std::vector<CEntity *> &entities, float dt)
{
    UNUSED(dt);
    m_entities = &entities;


    // do update for each entity
    for(CEntity *entity: *m_entities)
    {
        bool hasPosition = entity->hasComponent<SPositionComponent>();
        bool hasSpriteSheet = entity->hasComponent<SSpriteComponent>();
        if(hasPosition && hasSpriteSheet)
        {
            auto sprite = entity->getComponent<SSpriteComponent>();
            sprite->col = (SDL_GetTicks() / sprite->frameSpeed) % sprite->frameCount;
        }
    }

}

void CRenderSystem::render()
{

//     do update for each entity
    for(CEntity *entity: *m_entities)
    {
        bool hasPosition = entity->hasComponent<SPositionComponent>();
        bool hasSpriteSheet = entity->hasComponent<SSpriteComponent>();
        if(hasPosition && hasSpriteSheet)
        {
            auto sprite = entity->getComponent<SSpriteComponent>();
            auto position = entity->getComponent<SPositionComponent>();

            if(CTexture2DManager::instance()->loadTexture(sprite->textureId, sprite->source))
            {
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
        }
    }


}
END_NAMESPACE


