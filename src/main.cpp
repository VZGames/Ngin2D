#include <iostream>
#include "CNgin.h"
#include "CWorld.h"
#include "LoggerDefines.h"
#include "CSceneManager.h"
#include "SceneObjects/CGameScene.h"
#include "SceneObjects/CSettingScene.h"
#include "GameObjects/Player/CPlayer.h"
#include "GameObjects/Enemy/CEnemy.h"

using namespace engine;

int main(int argc, char *argv[])
{
    UNUSED(argc)
    UNUSED(argv)

    // Script
    Script::CGameScene gameScene;
    Script::CSettingScene settingScene;
    Script::CPlayer player;
    Script::CEnemy  enemy;
    Script::CEnemy  enemy2;
    Script::CEnemy  enemy3;

    std::vector<CEntity*> entities
        {
            &player,
            &enemy,
        };

    std::vector<AScene*> scenes
        {
            &gameScene,
            &settingScene
        };

    CWorld *world = engine::CWorld::instance()
                        ->registerEntities(entities)
                        ->registerScenes(scenes);

    CSceneManager::instance()->loadScene(gameScene.id(), E_LOAD_SCENE_MODE::SINGLE);

    if(engine::CNgin::instance()->initialize("Game Framework", 980, 620, world))
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
