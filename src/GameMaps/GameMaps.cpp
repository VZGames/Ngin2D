#include "GameMaps.h"
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>

#include "../Defines/StructsDef.h"

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
    Size mapSize, tileSize;

    int* matrix;

    ptr_rootElement = ptr_doc->RootElement();
    if(ptr_rootElement)
    {
        const char* width   = ptr_rootElement->Attribute("width");
        const char* height  = ptr_rootElement->Attribute("height");

        const char* tileWidth  = ptr_rootElement->Attribute("tilewidth");
        const char* tileHeight = ptr_rootElement->Attribute("tileheight");


        mapSize = {std::atoi(width), std::atoi(height)};
        tileSize = {std::atoi(tileWidth), std::atoi(tileHeight)};

        // allocate matrix 2D
        matrix = new int[mapSize.width * mapSize.height];

        for(TiXmlElement *e = ptr_rootElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
        {
            if(e->Value() == std::string("tileset"))
            {
                parse_tileset(e);
            } else if(e->Value() == std::string("layer"))
            {
                parse_layer(e);
            }
        }

    }

}

void GameMaps::parse_tileset(TiXmlElement *e)
{
    std::vector<TileSet> tilesets;
    // read tilesets element
    TiXmlElement* imageEle;

    const char* firstgid    = e->Attribute("firstgid");
    const char* name        = e->Attribute("name");
    const char* tileWidth   = e->Attribute("tilewidth");
    const char* tileHeight  = e->Attribute("tileheight");
    const char* tileCount   = e->Attribute("tilecount");
    const char* columns     = e->Attribute("columns");

    imageEle = e->FirstChildElement("image");
    if(imageEle)
    {
        const char* src         = imageEle->Attribute("source");
        const char* imgWidth    = imageEle->Attribute("width");
        const char* imgHeight   = imageEle->Attribute("height");
        Image image = {src, std::atoi(imgWidth), std::atoi(imgHeight)};
        TileSet tileSet = {
            std::atoi(firstgid),
            name, std::atoi(tileWidth),
            std::atoi(tileHeight),
            std::atoi(tileCount),
            std::atoi(columns),
            image
        };
        tilesets.push_back(tileSet);
    }


}

void GameMaps::parse_layer(TiXmlElement *e)
{
    std::vector<Layer> layers;

    // read layers element
    TiXmlElement* dataEle;
    const char* id = e->Attribute("id");
    const char* name = e->Attribute("name");
    const char* width = e->Attribute("width");
    const char* height = e->Attribute("height");

    Layer layer = {
        std::atoi(id),
        name,
        std::atoi(width),
        std::atoi(height)
    };

    layers.push_back(layer);


    dataEle = e->FirstChildElement("data");
    dataEle->GetText();
}
