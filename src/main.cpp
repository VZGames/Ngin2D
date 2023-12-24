#include <iostream>
#include "CNgin.h"
#include "CWorld.h"
#include "LoggerDefines.h"
#include "CSceneManager.h"
#include "SceneObjects/CGameScene.h"
#include "SceneObjects/CSettingScene.h"
#include "LoggerDefines.h"

using namespace engine;

int main(int argc, char *argv[])
{
    UNUSED(argc)
    UNUSED(argv)

    script::CGameScene gameScene;
    script::CSettingScene settingScene;

    CSceneManager::instance()->loadScene(gameScene.id(), E_LOAD_SCENE_MODE::SINGLE);

    if(engine::CNgin::instance()->initialize("Game Framework", 920, 640, engine::CWorld::instance()))
    {
        engine::CNgin::instance()->loop();
        engine::CNgin::instance()->clean();
        engine::CNgin::instance()->quit();
    }
    else
    {
        DBG("Can't initialize Game Game");
    }
    return 0;
}
