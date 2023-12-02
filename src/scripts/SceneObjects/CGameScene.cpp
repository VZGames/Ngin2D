#include "CGameScene.h"
#include "CSceneManager.h"
#include "LoggerDefines.h"
#include "CECSystemManager.h"
#include "CRenderSys.h"
#include "ComponentDef/SPositionComponent.h"
BEGIN_NAMESPACE(script)
CGameScene::CGameScene()
    :m_layout(100,100)
{
    engine::CSceneManager::instance()->createScene(__FUNCTION__, this);


    cow.setPosition(200, 50);
    cow2.setPosition(320, 100);
    cow3.setPosition(140, 80);

    m_entities.emplace_back(&player);
    m_entities.emplace_back(&cow);
    m_entities.emplace_back(&cow2);
    m_entities.emplace_back(&cow3);

    for(auto &entity: m_entities)
    {
        auto position = entity->getComponent<engine::SPositionComponent>();
        if(position == nullptr) continue;
        m_layout.insertEntity(entity->id(), position->x, position->y);
        engine::CWorld::instance()->registerEntity(entity);
    }
}

void CGameScene::init()
{
    engine::CECSystemManager::instance()->init(m_entities);
}

void CGameScene::update(float dt)
{
    std::thread([&, dt](){engine::CECSystemManager::instance()->update(m_entities, dt);}).join();
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



