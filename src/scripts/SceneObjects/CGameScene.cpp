#include "CGameScene.h"
#include "CSceneManager.h"
#include "Logger/LoggerDefines.h"

BEGIN_NAMESPACE(Script)
CGameScene::CGameScene()
{
    Ngin::CSceneManager::instance()->createScene(__FUNCTION__, this);
}
END_NAMESPACE

