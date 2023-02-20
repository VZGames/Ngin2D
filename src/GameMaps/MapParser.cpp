#include "MapParser.h"
#include "../Math/math2D.h"

MapParser *MapParser::s_instance = nullptr;

MapParser *MapParser::instance()
{
    return s_instance = (s_instance == nullptr)? new MapParser(): s_instance;
}

MapParser::MapParser()
{
    ptr_doc = new TiXmlDocument();
    if(loadTmx("2"))
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

        mapSize = {width, height};
        tileSize = {tileWidth, tileHeight};

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
    TiXmlElement* imageEle;

    int firstgid            = std::atoi(e->Attribute("firstgid"));
    const char* name        = e->Attribute("name");
    int tileWidth           = std::atoi(e->Attribute("tilewidth"));
    int tileHeight          = std::atoi(e->Attribute("tileheight"));
    int tileCount           = std::atoi(e->Attribute("tilecount"));
    int columns             = std::atoi(e->Attribute("columns"));
    int rows                = tileCount / columns;

    imageEle = e->FirstChildElement("image");
    if(imageEle)
    {
        const char* src         = imageEle->Attribute("source");
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
    TiXmlElement* dataEle;
    int id              = std::atoi(e->Attribute("id"));
    const char* name    = e->Attribute("name");
    int width           = std::atoi(e->Attribute("width"));
    int height          = std::atoi(e->Attribute("height"));


    dataEle = e->FirstChildElement("data");

    if(dataEle)
    {
        // allocate matrix 2D
        Matrix2D<int> matrix(height, width);

        const char* data = dataEle->GetText();
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
            matrix
        };

        layers.push_back(layer);
    }

}

void MapParser::parseGroup(TiXmlElement *e)
{
    int id              = std::atoi(e->Attribute("id"));
    const char* name    = e->Attribute("name");

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
        else if(groupEle->Value() == std::string("group"))
        {
            parseGroup(groupEle);
        }
    }
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

const std::vector<GroupLayer> &MapParser::getGroups() const
{
    return groups;
}


const std::vector<Layer> &MapParser::getLayers() const
{
    return layers;
}

const std::vector<TileSet> &MapParser::getTilesets() const
{
    return tilesets;
}
