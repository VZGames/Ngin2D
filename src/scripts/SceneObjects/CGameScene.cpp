#include "CGameScene.h"
#include "CSceneManager.h"
#include "LoggerDefines.h"
#include "CECSystemManager.h"
#include "CRenderSys.h"
#include "CBroadPhaseCulling.h"
#include "ComponentDef/SPositionComponent.h"
BEGIN_NAMESPACE(script)
CGameScene::CGameScene()
    :m_layout(255, 30, 30)
{
    engine::CSceneManager::instance()->createScene(__FUNCTION__, this);
}

void CGameScene::init()
{
    cow.setPosition(200, 50);
    cow2.setPosition(320, 100);
    cow3.setPosition(640, 80);

    m_entities.emplace_back(&player);
    m_entities.emplace_back(&cow);
    m_entities.emplace_back(&cow2);
    m_entities.emplace_back(&cow3);

    for(auto &entity: m_entities)
    {
        engine::CWorld::instance()->registerEntity(entity);

        auto position = entity->getComponent<engine::SPositionComponent>();

        if(position == nullptr) continue;
        engine::CBroadPhaseCulling::instance(1020, 30, 30)->insert(entity->id(), position->x, position->y);
    }

    engine::CECSystemManager::instance()->init(m_entities);
}

void CGameScene::update(float dt)
{
    engine::CBroadPhaseCulling::instance()->clean();
    engine::CECSystemManager::instance()->update(m_entities, dt);
}

void CGameScene::render()
{
    // [1] create new thread for render map
    for(engine::CEntity *entity: m_entities)
    {
        engine::CRenderSys::instance()->drawEntity(entity);
    }

    // [2] wait for all finished

}

END_NAMESPACE



