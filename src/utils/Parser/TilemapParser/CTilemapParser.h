#ifndef CTILEMAPPARSER_H
#define CTILEMAPPARSER_H

#include <vector>
#include "XMLParser/CXmlParser.h"
#include "tilemap_define.h"

class CTilemapParser
{
private:
    CXmlParser  m_xmlparser;
    TmxMap      m_map;

public:
    CTilemapParser();
    ~CTilemapParser();
    void loadFile(const char* file);

    void parse(TmxTileSet&tileset);
};

#endif // CTILEMAPPARSER_H
