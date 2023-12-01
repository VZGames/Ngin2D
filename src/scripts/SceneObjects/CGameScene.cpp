#include "CGameScene.h"
#include "CSceneManager.h"
#include "LoggerDefines.h"
#include "CECSystemManager.h"
#include "CLevelSys.h"
#include "CRenderSys.h"
#include "ComponentDef/SSpriteComponent.h"

BEGIN_NAMESPACE(script)
CGameScene::CGameScene()
{
    engine::CSceneManager::instance()->createScene(__FUNCTION__, this);


    cow.setPosition(200, 50);
    cow2.setPosition(320, 100);
    cow3.setPosition(140, 80);

    m_entities.emplace_back(&player);
    m_entities.emplace_back(&cow);
    m_entities.emplace_back(&cow2);
    m_entities.emplace_back(&cow3);

    m_levels.emplace_back(&originLv);

    engine::CWorld::instance()->registerEntity(&player);
    engine::CWorld::instance()->registerEntity(&cow);
    engine::CWorld::instance()->registerEntity(&cow2);
    engine::CWorld::instance()->registerEntity(&cow3);
}

void CGameScene::init()
{
    engine::CECSystemManager::instance()->init(m_entities);
}

void CGameScene::update(float dt)
{
    std::thread([dt](){engine::CLevelSys::instance()->update(dt);}).join();
    std::thread([&, dt](){engine::CECSystemManager::instance()->update(m_entities, dt);}).join();
}

void CGameScene::render()
{
    std::sort(m_entities.begin(), m_entities.end(), [](const engine::CEntity *A, const engine::CEntity *B){
        auto spriteA     = A->getComponent<engine::SSpriteComponent>();
        auto spriteB     = B->getComponent<engine::SSpriteComponent>();
        return spriteA->layer > spriteB->layer;
    });

    for(engine::CEntity *entity: m_entities)
    {
        engine::CRenderSys::instance()->drawEntity(entity);
    }


}

END_NAMESPACE



