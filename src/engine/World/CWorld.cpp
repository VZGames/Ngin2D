#include "CWorld.h"
#include "CECSystemManager.h"
#include "CRender.h"
#include "LoggerDefines.h"
#include "AScene.h"
#include "CEntity.h"
#include "CNgin.h"

BEGIN_NAMESPACE(engine)
CWorld* CWorld::s_instance = nullptr;
std::vector<CEntity*> CWorld::s_entities{};
std::vector<AScene*> CWorld::s_scenes{};

CWorld::CWorld(): b2World(m_gravity)
{
    m_gravity.SetZero();

    // Set the contact listener for the world
    SetContactListener(&m_my_contact);
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
}

void CWorld::update(float dt)
{
    CECSystemManager::instance()->update(dt);
    Step(m_timeStep, m_velocity_iterations, m_position_iterations);
}

void CWorld::render()
{
    forEachEntities(std::bind(&CRender::drawEntity, CRender::instance(), std::placeholders::_1));
}
END_NAMESPACE

