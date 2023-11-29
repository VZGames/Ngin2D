#include "CWorld.h"
#include "CSceneManager.h"
#include "CRenderSys.h"
#include "LoggerDefines.h"
#include "AScene.h"
#include "CEntity.h"
#include "ComponentDef/SSpriteComponent.h"

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

CWorld *CWorld::registerScene(AScene *scene)
{
    s_scenes.push_back(scene);
    return this;
}

void CWorld::forEachEntities(std::function<void(CEntity*)> fn)
{
    std::sort(s_entities.begin(), s_entities.end(), [](const CEntity *A, const CEntity *B){
        auto spriteA     = A->getComponent<SSpriteComponent>();
        auto spriteB     = B->getComponent<SSpriteComponent>();
        return spriteA->layer > spriteB->layer;
    });

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
    for(AScene *scene: s_scenes)
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

