#include "CSettingScene.h"
#include "CSceneManager.h"
#include "Logger/LoggerDefines.h"

BEGIN_NAMESPACE(GameScript)
CSettingScene::CSettingScene()
{
    GameNgin::CSceneManager::instance()->createScene(__FUNCTION__, this);
}
END_NAMESPACE
