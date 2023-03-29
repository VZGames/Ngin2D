#include "MapParser.h"
#include "Math/math2D.h"
#include <string>
#include <algorithm>

MapParser *MapParser::s_instance = nullptr;

MapParser *MapParser::instance()
{
    return s_instance = (s_instance == nullptr)? new MapParser(): s_instance;
}

MapParser::MapParser()
{
    ptr_doc = new TiXmlDocument();
    if(loadTmx("4"))
    {
        parseTmx();
    }
}

bool MapParser::loadTmx(const char *mapId)
{

    bool loadOk = ptr_doc->LoadFile(maps[mapId]);
    if(!loadOk)
    {
        return 0;
    }
    return 1;
}

void MapParser::parseTmx()
{
    ptr_rootElement = ptr_doc->RootElement();
    if(ptr_rootElement)
    {
        int width   = std::atoi(ptr_rootElement->Attribute("width"));
        int height  = std::atoi(ptr_rootElement->Attribute("height"));

        int tileWidth  = std::atoi(ptr_rootElement->Attribute("tilewidth"));
        int tileHeight = std::atoi(ptr_rootElement->Attribute("tileheight"));

        tileSize = {tileWidth, tileHeight};
        mapSize = {width * tileWidth, height * tileHeight};

        for(TiXmlElement *e = ptr_rootElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
        {
            if(e->Value() == std::string("tileset"))
            {
                parseTileset(e);
            }
            else if(e->Value() == std::string("layer"))
            {
                parseLayer(e);
            }
            else if(e->Value() == std::string("objectgroup"))
            {
                parseObjectLayer(e);
            }
            else if(e->Value() == std::string("group"))
            {
                parseGroup(e);
            }
        }

    }

    printf("Layers: %zd, Tilesets: %zd, Groups: %zd\n", layers.size(), tilesets.size(), groups.size());

}

void MapParser::parseTileset(TiXmlElement *e)
{
    // read tilesets element
    TiXmlElement *imageEle;

    int firstgid            = std::atoi(e->Attribute("firstgid"));
    const char *name        = e->Attribute("name");
    int tileWidth           = std::atoi(e->Attribute("tilewidth"));
    int tileHeight          = std::atoi(e->Attribute("tileheight"));
    int tileCount           = std::atoi(e->Attribute("tilecount"));
    int columns             = std::atoi(e->Attribute("columns"));
    int rows                = tileCount / columns;

    imageEle = e->FirstChildElement("image");
    if(imageEle)
    {
        const char *src         = imageEle->Attribute("source");
        int imgWidth            = std::atoi(imageEle->Attribute("width"));
        int imgHeight           = std::atoi(imageEle->Attribute("height"));
        Image image = {src, imgWidth, imgHeight};
        TileSet tileSet = {
            firstgid,
            name,
            tileWidth,
            tileHeight,
            tileCount,
            columns,
            rows,
            image
        };
        tilesets.push_back(tileSet);
    }


}

void MapParser::parseLayer(TiXmlElement *e)
{

    // read layers element
    TiXmlElement *dataEle;
    int id              = std::atoi(e->Attribute("id"));
    const char *name    = e->Attribute("name");
    int width           = std::atoi(e->Attribute("width"));
    int height          = std::atoi(e->Attribute("height"));
    bool visible        = e->LastAttribute()->Name() != std::string("visible"); // true if have not attribute

    dataEle = e->FirstChildElement("data");

    if(dataEle)
    {
        // allocate matrix 2D
        Matrix2D<int> matrix(height, width);

        const char *data = dataEle->GetText();
        std::string matrixStr(data);
        std::istringstream iss(matrixStr);
        std::string line;

        for (int row = 0; row < height; row++) {
            // read line
            for (int col = 0; col < width; col++) {

                std::getline(iss, line, ',');
                std::istringstream iss(line);

                int value;
                iss >> value;

                matrix.at(row, col) = value;
            }
        }

        Layer layer = {
            id,
            name,
            width,
            height,
            visible,
            matrix
        };

        layers.push_back(layer);
    }

}

void MapParser::parseObjectLayer(TiXmlElement *e)
{
    // read layers element
    int id              = std::atoi(e->Attribute("id"));
    const char *name    = e->Attribute("name");
    const char *color    = e->Attribute("color");

    ObjectLayer objectLayer = {
        id, name, color
    };

    for(TiXmlElement *objEle = e->FirstChildElement("object");
        objEle != NULL;
        objEle = objEle->NextSiblingElement("object"))
    {
        int id              = std::atoi(e->Attribute("id"));
        double x            = std::atoi(e->Attribute("x"));
        double y            = std::atoi(e->Attribute("y"));
        int width           = std::atoi(e->Attribute("width"));
        int height          = std::atoi(e->Attribute("height"));

        Object obj = {id, x, y, width, height};
        objectLayer.objects.push_back(obj);
    }
}

void MapParser::parseGroup(TiXmlElement *e)
{
    int id              = std::atoi(e->Attribute("id"));
    const char *name    = e->Attribute("name");

    GroupLayer group {
        id, name
    };

    groups.push_back(group);

    for(TiXmlElement *groupEle = e->FirstChildElement(); groupEle != NULL; groupEle = groupEle->NextSiblingElement())
    {
        if(groupEle->Value() == std::string("layer"))
        {
            parseLayer(groupEle);
        }
        else if(groupEle->Value() == std::string("objectgroup"))
        {
            parseObjectLayer(groupEle);
        }
        else if(groupEle->Value() == std::string("group"))
        {
            parseGroup(groupEle);
        }
    }
}

const Size &MapParser::getTileSize() const
{
    return tileSize;
}

void MapParser::findById(int tileId, TileSet &result) const
{
    for (auto tileset: tilesets) {
        if(tileId >= tileset.firstgid && tileId < tileset.firstgid + (tileset.count))
        {
            result = tileset;
            return;
        }
    }
    return;
}

const Size MapParser::getMapSize() const
{
    return mapSize;
}

const std::vector<GroupLayer> &MapParser::getGroups() const
{
    return groups;
}

const GroupLayer MapParser::getGroupByName(const char *name) const
{
    GroupLayer group = {NULL, NULL, std::vector<Layer>{}};
    for(auto &_group: groups)
    {
        if(name == _group.name)
        {
            group = _group;
        }
    }
    return group;
}

const GroupLayer MapParser::getGroupByID(const int &id) const
{
    GroupLayer group = {NULL, NULL, std::vector<Layer>{}};
    for(auto &_group: groups)
    {
        if(id == _group.id)
        {
            group = _group;
        }
    }
    return group;
}


const std::vector<Layer> &MapParser::getLayers() const
{
    return layers;
}

const std::vector<TileSet> &MapParser::getTilesets() const
{
    return tilesets;
}
