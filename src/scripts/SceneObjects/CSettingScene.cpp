#include "CSettingScene.h"
#include "CSceneManager.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(script)
CSettingScene::CSettingScene()
{
    engine::CSceneManager::instance()->createScene(__FUNCTION__, this);
}
END_NAMESPACE
