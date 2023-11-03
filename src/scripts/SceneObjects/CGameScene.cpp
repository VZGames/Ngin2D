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

void CGameScene::render()
{
}
END_NAMESPACE

