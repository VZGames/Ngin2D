#include <iostream>
#include "CNgin.h"
#include "LoggerDefines.h"

using namespace GameNgin;

int main(int argc, char *argv[])
{
    UNUSED(argc)
    UNUSED(argv)

    if(GameNgin::CNgin::instance()->initialize("Game Framework", 980, 620))
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
