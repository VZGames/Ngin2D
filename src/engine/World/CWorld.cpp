#include "CWorld.h"
#include "CECSystemManager.h"
#include "Scene/CSceneManager.h"
#include "LoggerDefines.h"
#include "CCamera.h"
#include "AScene.h"
#include "CEntity.h"

BEGIN_NAMESPACE(Ngin)
CWorld* CWorld::s_instance = nullptr;
std::vector<CEntity*> CWorld::s_entities{};
std::vector<AScene*> CWorld::s_scenes{};

CWorld::CWorld()
{

}

CWorld* CWorld::instance()
{
    return s_instance = (s_instance == nullptr)? new CWorld():s_instance;
}

CWorld *CWorld::registerEntities(std::vector<CEntity*> &entities)
{
    s_entities = std::move(entities);
    return this;
}

CWorld *CWorld::registerScenes(std::vector<AScene*> &scenes)
{
    s_scenes = std::move(scenes);
    return this;
}

void CWorld::forEachEntities(std::function<void(CEntity*)> fn)
{
    for(CEntity *entity: s_entities)
    {
        fn(entity);
    }
}

void CWorld::forEachScenes(std::function<void(AScene*)> fn)
{
    for(AScene *scene: s_scenes)
    {
        fn(scene);
    }
}

void CWorld::init()
{
    CECSystemManager::instance()->init(s_entities);
    for(AScene *scene: s_scenes)
    {
        scene->init();
    }
}

void CWorld::update(float dt)
{
    CECSystemManager::instance()->update(dt);
}

void CWorld::render()
{
    CECSystemManager::instance()->render();
}
END_NAMESPACE

