#include <iostream>
#include "CNgin.h"
#include "CWorld.h"
#include "LoggerDefines.h"
#include "CSceneManager.h"
#include "SceneObjects/CGameScene.h"
#include "SceneObjects/CSettingScene.h"
#include "GameObjects/Player/CPlayer.h"
#include "GameObjects/Enemy/CEnemy.h"


using namespace GameNgin;

int main(int argc, char *argv[])
{
    UNUSED(argc)
    UNUSED(argv)

    // gamescript
    GameScript::CGameScene gameScene;
    GameScript::CSettingScene settingScene;
    GameScript::CPlayer player;
    GameScript::CEnemy  enemy;
    GameScript::CEnemy  enemy2;
    GameScript::CEnemy  enemy3;

    std::vector<CEntity*> entities
        {
            &player,
            &enemy,
            &enemy2
        };

    std::vector<AScene*> scenes
        {
            &gameScene,
            &settingScene
        };

    CWorld *world = GameNgin::CWorld::instance();
    CSceneManager::instance()->loadScene(gameScene.id(), E_LOAD_SCENE_MODE::SINGLE);

    if(GameNgin::CNgin::instance()->initialize("Game Framework", 980, 620, world))
    {
        world->registerEntities(entities);
        world->registerScenes(scenes);

        GameNgin::CNgin::instance()->loop();
        GameNgin::CNgin::instance()->clean();
        GameNgin::CNgin::instance()->quit();
    }
    else
    {
        MORGAN_DEBUG("Can't initialize Game Game");
    }
    return 0;
}
