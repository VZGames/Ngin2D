#include "CWorld.h"
#include "CSceneManager.h"
#include "CRenderSys.h"
#include "LoggerDefines.h"
#include "AScene.h"
#include "CEntity.h"

BEGIN_NAMESPACE(engine)
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

CWorld *CWorld::registerEntities(std::vector<CEntity*> entities)
{
    std::copy(entities.begin(), entities.end(), std::back_inserter(s_entities));
    return this;
}

CWorld *CWorld::registerScenes(std::vector<AScene *> scenes)
{
    std::copy(scenes.begin(), scenes.end(), std::back_inserter(s_scenes));
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
    CSceneManager::instance()->currentScene()->init();
}

void CWorld::update(float dt)
{
    CSceneManager::instance()->currentScene()->update(dt);
}

void CWorld::render()
{
    forEachEntities(std::bind(&CRenderSys::drawFrame, CRenderSys::instance(), std::placeholders::_1));
}
END_NAMESPACE

