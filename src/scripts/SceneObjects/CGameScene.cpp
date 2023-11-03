#include "CGameScene.h"
#include "CSceneManager.h"
#include "Logger/LoggerDefines.h"

BEGIN_NAMESPACE(GameScript)
CGameScene::CGameScene()
{
    GameNgin::CSceneManager::instance()->createScene(__FUNCTION__, this);
}

void CGameScene::init()
{

}

void CGameScene::update(std::vector<GameNgin::CEntity*> &entities, float dt)
{
    std::vector<GameNgin::CEntity*>::iterator it = entities.begin();
    while (it != entities.end())
    {

        ++it;
    }
}

void CGameScene::render()
{
}
END_NAMESPACE

