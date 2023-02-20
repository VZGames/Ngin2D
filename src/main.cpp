#include <iostream>
#include "Game/Game.h"


int main(int argc, char *argv[])
{
    if(Game::instance()->InitGame("8888"))
    {
        Game::instance()->Loop();
        Game::instance()->Clean();
        Game::instance()->Quit();
    }
    else
    {
        std::cout << "Can't initialize Game Game\n";
    }
    return 0;
}
