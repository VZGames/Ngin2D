#include <iostream>
#include "Engine/Engine.h"


int main(int argc, char *argv[])
{
    if(Engine::instance()->init_game("HaTNK"))
    {
        Engine::instance()->loop_game();
        Engine::instance()->release_resource();
        Engine::instance()->quit_game();
    }
    else
    {
        std::cout << "Can't initialize Game Engine\n";
    }
    return 0;
}
