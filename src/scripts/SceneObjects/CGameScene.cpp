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

void CGameScene::update(float dt)
{
    MORGAN_DEBUG("XXXXXXXXXXXXXXXXX %f", dt)
}

void CGameScene::render()
{

}
END_NAMESPACE

