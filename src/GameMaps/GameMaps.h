#ifndef GAMEMAPS_H
#define GAMEMAPS_H

#include <map>
#include "../Utils/TinyXML/tinyxml.h"


class GameMaps
{
public:
    GameMaps();

private:
    bool load_tmx(const char *mapId);
    void parse_tmx();


private:
    std::map<const char*, const char*> maps = {
        {"start", "../../assets/Map1.tmx"},
        {"xxx", "../../assets/Map2.tmx"}
    };

    TiXmlDocument *ptr_doc;
    TiXmlElement *ptr_rootElement;
};

#endif // GAMEMAPS_H
