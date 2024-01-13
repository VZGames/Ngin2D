#include "CEntityRenderer.h"
#include "Camera/CCameraSys.h"
#include "CEntity.h"
#include "CTexture2DManager.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SBoxComponent.h"
using namespace engine;

CEntityRenderer::CEntityRenderer()
{

}

bool CEntityRenderer::render(void* data, float scale)
{
    if (identify_type(data).compare("CEntity") != 0)
    {
        return false;
    }
    else
    {
        CEntity *entity = static_cast<CEntity *>(data);
        Offset *offset = CCameraSys::instance()->offset();
        auto sprite = entity->getComponent<SSpriteComponent>();
        auto position = entity->getComponent<SPositionComponent>();
        auto box = entity->getComponent<SBoxComponent>();

        if ((position && sprite))
        {
            float x = position->x - offset->x;
            float y = position->y - offset->y;

            Point2DF pos(x, y);

            CTexture2DManager::instance()
                ->drawFrame(
                    sprite->textureId,
                    pos,
                    sprite->frameWidth,
                    sprite->frameHeight,
                    sprite->row,
                    sprite->col,
                    scale);

            CTexture2DManager::instance()->drawRect(pos,
                                                    sprite->frameWidth,
                                                    sprite->frameHeight,
                                                    scale);

            if (box)
            {
                CTexture2DManager::instance()->drawPolygon(pos, box->vertices(), scale);
            }
        }
    }

    return true;
}
