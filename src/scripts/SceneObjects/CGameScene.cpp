#include "CGameScene.h"
#include "CSceneManager.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(script)
CGameScene::CGameScene()
{
    engine::CSceneManager::instance()->createScene(__FUNCTION__, this);
}
END_NAMESPACE

