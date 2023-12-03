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
    int countWith(const char* tag);

    TmxMap map() const;
    void parse(int index, TmxTileSet&tileset);
    void parse(int index, TmxLayer  &layer);

};

#endif // CTILEMAPPARSER_H
