#include "CRender.h"
#include "CEntity.h"
#include "CTexture2DManager.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SSpriteComponent.h"
BEGIN_NAMESPACE(Ngin)
CRender *CRender::s_instance = nullptr;
CRender::CRender()
{

}

CRender *CRender::instance()
{
    return s_instance = (s_instance == nullptr)? new CRender(): s_instance;
}

void CRender::drawEntity(CEntity *entity)
{
    bool hasPosition = entity->hasComponent<SPositionComponent>();
    bool hasSpriteSheet = entity->hasComponent<SSpriteComponent>();
    if((hasPosition && hasSpriteSheet))
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

}
END_NAMESPACE

