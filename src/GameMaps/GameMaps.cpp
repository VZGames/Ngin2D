#include "GameMaps.h"
#include <stdio.h>
#include <cstdlib>
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
    std::vector<TileSet> tilesets;
    std::vector<Layer> layers;
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

        // read tilesets element
        TiXmlElement* tilesetEle = ptr_rootElement->FirstChildElement("tileset");
        TiXmlElement* imageEle;

        for (; tilesetEle != NULL; tilesetEle = tilesetEle->NextSiblingElement("tileset"))
        {
            const char* firstgid    = tilesetEle->Attribute("firstgid");
            const char* name        = tilesetEle->Attribute("name");
            const char* tileWidth   = tilesetEle->Attribute("tilewidth");
            const char* tileHeight  = tilesetEle->Attribute("tileheight");
            const char* tileCount   = tilesetEle->Attribute("tilecount");
            const char* columns     = tilesetEle->Attribute("columns");

            imageEle = tilesetEle->FirstChildElement("image");
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

        // read layers element
        TiXmlElement* layerEle = ptr_rootElement->FirstChildElement("layer");
        TiXmlElement* dataEle;
        for(; layerEle != NULL; layerEle = layerEle->NextSiblingElement("layer"))
        {
            const char* id = layerEle->Attribute("id");
            const char* name = layerEle->Attribute("name");
            const char* width = layerEle->Attribute("width");
            const char* height = layerEle->Attribute("height");

            Layer layer = {
                std::atoi(id),
                name,
                std::atoi(width),
                std::atoi(height)
            };

            layers.push_back(layer);


            dataEle = layerEle->FirstChildElement("data");
            dataEle->GetText();

        }

    }

}
