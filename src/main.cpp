#include <iostream>
#include "CNgin.h"
#include "CWorld.h"
#include "LoggerDefines.h"

using namespace GameNgin;

int main(int argc, char *argv[])
{
    UNUSED(argc)
    UNUSED(argv)

    CWorld *world = GameNgin::CWorld::instance();
    world->registerEntity(nullptr);
    world->registerScene(nullptr);

    if(GameNgin::CNgin::instance()->initialize("Game Framework", 980, 620, world))
    {
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
