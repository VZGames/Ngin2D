#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <map>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

#include "Utils/TinyXML/tinyxml.h"
#include "Defines/Defines.h"

#include "ECS/Entity/Entity.h"

class MapParser
{
public:
    static MapParser *instance();

    void findById(int tileId, TileSet &tileset) const;

    const Size getMapSize() const;
    const std::vector<Layer> &getLayers() const;
    const std::vector<TileSet> &getTilesets() const;
    const std::vector<GroupLayer> &getGroups() const;

    const GroupLayer getGroupByName(const char *name) const;
    const GroupLayer getGroupByID(const int &id) const;

    const Size &getTileSize() const;

private:
    MapParser();
    bool loadTmx(const char *mapId);
    void parseTmx();
    void parseTileset(TiXmlElement *e);
    void parseLayer(TiXmlElement *e);
    void parseObjectLayer(TiXmlElement *e);
    void parseGroup(TiXmlElement *e);


private:

    static MapParser *s_instance;
    std::map<std::string, const char*> maps = {
        {"1", "./assets/Map1.tmx"},
        {"2", "./assets/Map2.tmx"},
        {"3", "./assets/Map3.tmx"},
        {"4", "./assets/Map4.tmx"},
    };

    Size mapSize, tileSize;
    std::vector<Layer> layers;
    std::vector<Object> objects;
    std::vector<GroupLayer> groups;
    std::vector<TileSet> tilesets;

    std::vector<Point2DI> colliders;

    TiXmlDocument *ptr_doc;
    TiXmlElement *ptr_rootElement;
};

#endif // MAPPARSER_H
