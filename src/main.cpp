#define SDL_MAIN_HANDLED

#include <iostream>
#include "Engine/Engine.h"


int main(int argc, char *argv[])
{
    Engine::instance()->init_game("XYZ");
    Engine::instance()->loop_game();
    Engine::instance()->quit_game();

    return 0;
}
