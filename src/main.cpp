#include <iostream>
#include "Engine/Engine.h"


int main(int argc, char *argv[])
{
    if(Engine::instance()->InitGame("8888"))
    {
        Engine::instance()->Loop();
        Engine::instance()->Clean();
        Engine::instance()->Quit();
    }
    else
    {
        std::cout << "Can't initialize Game Engine\n";
    }
    return 0;
}
