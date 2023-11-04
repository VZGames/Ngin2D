#include "CWorld.h"
#include "CECSystemManager.h"
#include "Scene/CSceneManager.h"

BEGIN_NAMESPACE(GameNgin)
CWorld* CWorld::s_instance = nullptr;
CWorld::CWorld()
{

}

CWorld* CWorld::instance()
{
    return s_instance = (s_instance == nullptr)? new CWorld():s_instance;
}

void CWorld::registerEntities(std::vector<CEntity*> &entities)
{
    std::vector<CEntity*>::iterator it = entities.begin();
    while (it != entities.end())
    {
        m_entities.push_back(*it);
        ++it;
    }
}

void CWorld::registerScenes(std::vector<AScene*> &scenes)
{
    std::vector<AScene*>::iterator it = scenes.begin();
    while (it != scenes.end())
    {
        m_scenes.push_back(*it);
        ++it;
    }
}

void CWorld::init()
{
    CECSystemManager::instance()->init();
}

void CWorld::update(float dt)
{
    CECSystemManager::instance()->update(m_entities, dt);
}

void CWorld::render()
{
    CECSystemManager::instance()->render();
}
END_NAMESPACE

