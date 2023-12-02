#include "CTilemapParser.h"
#include "Utils.h"

CTilemapParser::CTilemapParser()
{

}

CTilemapParser::~CTilemapParser()
{
    safeRelease(m_map.tilesets);
    safeRelease(m_map.layers);
}

void CTilemapParser::loadFile(const char *file)
{
    m_xmlparser.loadFile(file);

    m_map.tilesets = new TmxTileSet[m_xmlparser.count("tileset")];
    m_map.layers   = new TmxLayer[m_xmlparser.count("layer")];
}

void CTilemapParser::parse(TmxTileSet &tileset)
{
    const char* tag = "tileset";

    int index = 0;

    tileset.first_global_id = std::stoi(m_xmlparser.parseTagWith(index, tag, "firstgid"));
    tileset.columns         = std::stoi(m_xmlparser.parseTagWith(index, tag, "columns"));
}

