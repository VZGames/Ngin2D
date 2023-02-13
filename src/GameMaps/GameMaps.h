#ifndef GAMEMAPS_H
#define GAMEMAPS_H

#include "TinyXML/tinyxml.h"

class GameMaps
{
public:
    GameMaps();

private:
    bool loadMap(const char* filePath);
};

#endif // GAMEMAPS_H
