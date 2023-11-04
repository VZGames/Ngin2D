#include "CWorld.h"
#include "CECSystemManager.h"
#include "Scene/CSceneManager.h"
#include "LoggerDefines.h"
#include "CCamera.h"

BEGIN_NAMESPACE(Ngin)
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
    m_entities = &entities;
}

void CWorld::registerScenes(std::vector<AScene*> &scenes)
{
    m_scenes = &scenes;
}

void CWorld::init()
{
    CECSystemManager::instance()->init();
}

void CWorld::update(float dt)
{
    CECSystemManager::instance()->update(*m_entities, dt);
}

void CWorld::render()
{
    CECSystemManager::instance()->render();
}
END_NAMESPACE

