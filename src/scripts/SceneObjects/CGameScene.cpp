#include "CGameScene.h"
#include "CSceneManager.h"
#include "LoggerDefines.h"
#include "CECSystemManager.h"
#include "CRenderSys.h"
#include "CBroadPhaseCulling.h"
#include "ComponentDef/SPositionComponent.h"


BEGIN_NAMESPACE(script)
CGameScene::CGameScene()
{
    engine::CSceneManager::instance()->createScene(__FUNCTION__, this);
}

void CGameScene::init()
{
    // space init entities
    {
        cow.setPosition(200, 50);
        cow2.setPosition(320, 100);
        cow3.setPosition(640, 400);

        m_entities.emplace_back(&player);
        m_entities.emplace_back(&cow);
        m_entities.emplace_back(&cow2);
        m_entities.emplace_back(&cow3);

        for(auto &entity: m_entities)
        {
            engine::CWorld::instance()->registerEntity(entity);

            auto position = entity->getComponent<engine::SPositionComponent>();

            if(position == nullptr) continue;
            engine::CBroadPhaseCulling::instance()->insert(entity->id(),position->x, position->y);
        }

        engine::CECSystemManager::instance()->init(m_entities);
    }


    // space init map/level
    {
        m_tilemap.loadMap("./debug/assets/Maps/PhuHoa.tmx");
    }
}

void CGameScene::update(float dt)
{
    engine::CBroadPhaseCulling::instance()->clean();
    engine::CECSystemManager::instance()->update(m_entities, dt);
    m_tilemap.update(dt);


    std::sort(m_entities.begin(), m_entities.end(), [](const engine::CEntity *A, const engine::CEntity *B){
        auto spriteA     = A->getComponent<engine::SSpriteComponent>();
        auto spriteB     = B->getComponent<engine::SSpriteComponent>();
        return spriteA->zOrder < spriteB->zOrder;
    });
}

void CGameScene::render()
{
    // [1] create new threads for render
    m_tilemap.render();

    for(engine::CEntity *entity: m_entities)
    {
        engine::CRenderSys::instance()->drawEntity(entity);
    }

    // [2] wait for all finished

}

END_NAMESPACE



