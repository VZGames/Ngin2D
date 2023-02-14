#include "GameMaps.h"


GameMaps::GameMaps()
{
    ptr_doc = new TiXmlDocument();
    if(load_tmx("start"))
    {
        parse_tmx();
    }
}

bool GameMaps::load_tmx(const char *mapId)
{

    bool loadOk = ptr_doc->LoadFile(maps[mapId]);
    if(!loadOk)
    {
        return 0;
    }
    return 1;
}

void GameMaps::parse_tmx()
{
    ptr_rootElement = ptr_doc->RootElement();
}
