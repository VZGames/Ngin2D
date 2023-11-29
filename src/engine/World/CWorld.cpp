#include "CWorld.h"
#include "CSceneManager.h"
#include "LoggerDefines.h"
#include "AScene.h"
#include "CEntity.h"

BEGIN_NAMESPACE(engine)
CWorld* CWorld::s_instance = nullptr;
CWorld::CWorld()
{
}

CWorld* CWorld::instance()
{
    return s_instance = (s_instance == nullptr)? new CWorld():s_instance;
}

CWorld *CWorld::registerEntities(std::vector<CEntity*> entities)
{
    std::copy(entities.begin(), entities.end(), std::back_inserter(m_entities));
    return this;
}

CWorld *CWorld::registerScene(AScene *scene)
{
    m_scenes.push_back(scene);
    return this;
}

void CWorld::init()
{
    for(AScene *scene: m_scenes)
    {
        scene->init();
    }
}

void CWorld::update(float dt)
{
    CSceneManager::instance()->currentScene()->update(dt);
}

void CWorld::render()
{
    CSceneManager::instance()->currentScene()->render();
}
END_NAMESPACE

