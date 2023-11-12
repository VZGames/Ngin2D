#include <iostream>
#include "CNgin.h"
#include "CWorld.h"
#include "LoggerDefines.h"
#include "CSceneManager.h"
#include "SceneObjects/CGameScene.h"
#include "SceneObjects/CSettingScene.h"
#include "GameObjects/Player/CPlayer.h"
#include "GameObjects/Enemy/CEnemy.h"
#include "GameObjects/Cows/CCow.h"

using namespace engine;

int main(int argc, char *argv[])
{
    UNUSED(argc)
    UNUSED(argv)

    // Script
    script::CGameScene gameScene;
    script::CSettingScene settingScene;
    script::CPlayer player;
    script::CEnemy  enemy(300, 70);
    script::CEnemy  enemy2(100, 300);
    script::CEnemy  enemy3(500, 260);
    script::CCow    cow(100, 50);
    script::CCow    cow2(50, 20);
    script::CCow    cow3(300, 400);

    std::vector<CEntity*> entities
        {
            &enemy,
            &enemy2,
            &enemy3,
            &cow,
            &cow2,
            &cow3,
            &player,
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
