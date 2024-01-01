#include "CWorld.h"
#include "CSceneManager.h"
#include "LoggerDefines.h"
#include "AScene.h"
#include "CEntity.h"

using namespace engine;
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
    m_entities.push_back(entity);
    return this;
}

void CWorld::unRegisterEntity(CEntity* entity)
{
    std::vector<CEntity*>::iterator it = m_entities.begin();
    while(it != m_entities.end())
    {
        if((*it)->id() == entity->id())
        {
            m_entities.erase(it);
            break;
        }
        it++;
    }
}

CWorld *CWorld::registerScene(AScene *scene)
{
    m_scenes.push_back(scene);
    return this;
}

void CWorld::unRegisterScene(AScene *scene)
{
    std::vector<AScene*>::iterator it = m_scenes.begin();
    while(it != m_scenes.end())
    {
        if((*it)->id() == scene->id())
        {
            m_scenes.erase(it);
            break;
        }
        it++;
    }
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





