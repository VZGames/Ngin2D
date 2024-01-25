#ifndef CTILEMAPPARSER_H
#define CTILEMAPPARSER_H

#include <vector>
#include "XMLParser/CXmlParser.h"
#include "TmxFormat.h"

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

    TmxMap &map();
    void parse(int index, TmxTileSet&tileset);
    void parse(int index, TmxLayer  &layer);
    void parse(int index, TmxObjectGroup &objectgroup);
    void parse(int index, TmxObject &object);
    void parse(int index, TmxRectangle &shape);
    void parse(int index, TmxPoint &shape);
    void parse(int index, TmxEllipse &shape);
    void parse(int index, TmxPolygon &shape);

};

#endif // CTILEMAPPARSER_H
