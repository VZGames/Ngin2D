#include "GameMaps.h"
#include "LayerManager.h"

namespace ngin2D {
GameMaps *GameMaps::s_instance = nullptr;

GameMaps::GameMaps()
{
}

GameMaps *GameMaps::instance()
{
    return s_instance = (s_instance == nullptr)? new GameMaps(): s_instance;
}

void GameMaps::draw()
{
    LayerManager::instance()->draw();
}

void GameMaps::update()
{

}

void GameMaps::clean()
{

}

}
