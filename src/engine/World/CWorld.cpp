#include "CWorld.h"
#include "CECSystemManager.h"
#include "Scene/CSceneManager.h"
#include "LoggerDefines.h"
#include "CCamera.h"

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

void CWorld::forEachEntities(void (*fn)(CEntity* entity))
{
    for(CEntity *entity: s_entities)
    {
        fn(entity);
    }
}

void CWorld::forEachScenes(void (*fn)(AScene* scene))
{
    for(AScene *scene: s_scenes)
    {
        fn(scene);
    }
}

void CWorld::init()
{
    CECSystemManager::instance()->init(s_entities, s_scenes);
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

