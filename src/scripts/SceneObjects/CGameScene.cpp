#include "CGameScene.h"
#include "CSceneManager.h"
#include "LoggerDefines.h"
#include "CECSystemManager.h"
#include "CLevelManager.h"

BEGIN_NAMESPACE(script)
CGameScene::CGameScene()
{
    engine::CSceneManager::instance()->createScene(__FUNCTION__, this);

    m_entities.emplace_back(&cow);
    m_entities.emplace_back(&cow2);
    m_entities.emplace_back(&cow3);
    m_entities.emplace_back(&player);



    cow.setPosition(200, 50);
    cow2.setPosition(320, 100);
    cow3.setPosition(140, 80);

    engine::CWorld::instance()->registerEntities(m_entities);
}

void CGameScene::init()
{
    engine::CECSystemManager::instance()->init(m_entities);
}

void CGameScene::update(float dt)
{
    std::thread([dt](){engine::CLevelManager::instance()->update(dt);}).join();
    std::thread([&, dt](){engine::CECSystemManager::instance()->update(m_entities, dt);}).join();
}
END_NAMESPACE


