#include "CRender.h"
#include "CEntity.h"
#include "CTexture2DManager.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SBoxComponent.h"

BEGIN_NAMESPACE(engine)
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
    auto sprite = entity->getComponent<SSpriteComponent>();
    auto position = entity->getComponent<SPositionComponent>();
    auto box = entity->getComponent<SBoxComponent>();
    if((position && sprite))
    {
        CTexture2DManager::instance()->drawFrame(
            sprite->textureId,
            Point2DF(position->x, position->y),
            sprite->frameWidth,
            sprite->frameHeight,
            sprite->row,
            sprite->col
            );

        if(box)
        {
            CTexture2DManager::instance()->drawPolygon(box->vertices());
        }
    }

}
END_NAMESPACE

