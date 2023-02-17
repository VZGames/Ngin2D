#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <map>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

#include "../Utils/TinyXML/tinyxml.h"
#include "../Defines/StructsDef.h"


class MapParser
{
public:
    static MapParser *instance();

    const std::vector<Layer> &getLayers() const;
    const std::vector<TileSet> &getTilesets() const;

private:
    MapParser();
    bool load_tmx(const char *mapId);
    void parse_tmx();
    void parse_tileset(TiXmlElement* e);
    void parse_layer(TiXmlElement* e);
    void parse_group(TiXmlElement* e);

private:

    static MapParser *s_instance;
    std::map<const char*, const char*> maps = {
        {"start", "./assets/Map1.tmx"},
        {"xxx", "./assets/Map2.tmx"}
    };

    Size mapSize, tileSize;
    std::vector<Layer> layers;
    std::vector<GroupLayer> groups;
    std::vector<TileSet> tilesets;

    TiXmlDocument* ptr_doc;
    TiXmlElement* ptr_rootElement;
};

#endif // MAPPARSER_H
