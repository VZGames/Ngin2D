#include <iostream>
#include "CNgin.h"
#include "CWorld.h"
#include "LoggerDefines.h"
#include "SceneObjects/CGameScene.h"
#include "GameObjects/Player/CPlayer.h"
#include "GameObjects/Enemy/CEnemy.h"


using namespace GameNgin;

int main(int argc, char *argv[])
{
    UNUSED(argc)
    UNUSED(argv)

    // gamescript
    GameScript::CGameScene gameScene;

    GameScript::CPlayer player;
    GameScript::CEnemy  enemy;
    GameScript::CEnemy  enemy2;
    GameScript::CEnemy  enemy3;

    std::vector<CEntity*> entities
        {
            &player,
            &enemy,
            &enemy2,
            &enemy3
        };

    std::vector<AScene*> scenes
        {
            &gameScene,
        };

    CWorld *world = GameNgin::CWorld::instance();
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
