#include "CSettingScene.h"
#include "CSceneManager.h"
#include <LoggerDefines.h>

using namespace script;
CSettingScene::CSettingScene()
{
    engine::CSceneManager::instance()->createScene(__FUNCTION__, this);
}

