#include "CGameScene.h"
#include "CSceneManager.h"
#include "LoggerDefines.h"
#include "CECSystemManager.h"

BEGIN_NAMESPACE(script)
CGameScene::CGameScene()
{
    engine::CSceneManager::instance()->createScene(__FUNCTION__, this);

    m_entities.emplace_back(&player);
    m_entities.emplace_back(&cow);

    engine::CWorld::instance()->registerEntities(m_entities);
}

void CGameScene::init()
{
    engine::CECSystemManager::instance()->init(m_entities);
}

void CGameScene::update(float dt)
{
    engine::CECSystemManager::instance()->update(m_entities, dt);
}
END_NAMESPACE


