#include "CSettingScene.h"
#include "CSceneManager.h"
#include "Logger/LoggerDefines.h"

BEGIN_NAMESPACE(Script)
CSettingScene::CSettingScene()
{
    Ngin::CSceneManager::instance()->createScene(__FUNCTION__, this);
}
END_NAMESPACE
