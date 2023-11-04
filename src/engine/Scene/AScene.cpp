#include "AScene.h"
#include "CECSystemManager.h"

BEGIN_NAMESPACE(GameNgin)

void AScene::init()
{

}

void AScene::update(std::vector<GameNgin::CEntity *> &entities, float dt)
{
    CECSystemManager::instance()->update(entities, dt);
}

void AScene::render()
{

}

const char *AScene::id() const
{
    return m_id;
}

END_NAMESPACE
