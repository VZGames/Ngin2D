#include "CGameScene.h"
#include "CSceneManager.h"
#include <LoggerDefines.h>
#include "CECSystemManager.h"
#include "Render/CRenderSys.h"
#include "CBroadPhaseCulling.h"
#include "ComponentDef/SBoxComponent.h"
#include "CNgin.h"
#include "Define/Assets/DefineMaps.h"

using namespace script;
class CEntity;
CGameScene::CGameScene()
    :m_tilemap(engine::CTilemap::instance())
{
    engine::CSceneManager::instance()->createScene(__FUNCTION__, this);
}

void CGameScene::init()
{
    // space init entities
    {
        cow.setPosition(320, 300);
        cow2.setPosition(768, 144);
        cow3.setPosition(640, 400);

        m_entities.emplace_back(&player);
        // m_entities.emplace_back(&cow);
        // m_entities.emplace_back(&cow2);
        // m_entities.emplace_back(&cow3);

        engine::CRenderSys::instance()->clearItems();
        for (auto &entity : m_entities)
        {
            engine::CRenderSys::instance()->addItem<engine::CEntity*>(&entity);
            engine::CWorld::instance()->registerEntity(entity);

            auto box = entity->getComponent<engine::SBoxComponent>();

            if(box == nullptr) continue;
            engine::CBroadPhaseCulling::instance()->insert(entity->id(),box->shape.center().x, box->shape.center().y);
        }

        engine::CECSystemManager::instance()->init(m_entities);
    }


    // space init map/level
    {
        m_tilemap->loadMap(PHU_HOA);
        engine::CCameraSys::instance()->setViewport(engine::CNgin::windowSize().width,
                                                    engine::CNgin::windowSize().height);

        this->setBoundary(m_tilemap->coord_limit());
    }
}

void CGameScene::update(float dt)
{
    engine::CBroadPhaseCulling::instance()->clean();
    engine::CECSystemManager::instance()->update(m_entities, dt);
    m_tilemap->update(m_entities, dt);


    std::sort(m_entities.begin(), m_entities.end(), [](const engine::CEntity *A, const engine::CEntity *B){
        auto spriteA     = A->getComponent<engine::SSpriteComponent>();
        auto spriteB     = B->getComponent<engine::SSpriteComponent>();
        return spriteA->zOrder < spriteB->zOrder;
    });
}

void CGameScene::render()
{
    // [1] create new threads for render
    m_tilemap->render();

    engine::CRenderSys::instance()->draw();
    
    // [2] wait for all finished

}





