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

CWorld *CWorld::registerEntity(CEntity* entity)
{
    m_entities.emplace_back(entity);
    return this;
}

CWorld *CWorld::registerScene(AScene *scene)
{
    m_scenes.emplace_back(scene);
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

