#ifndef CTILEMAP_H
#define CTILEMAP_H

#include <stack>
#include "CommonDefine.h"
#include "TilemapParser/CTilemapParser.h"
#include "Tileset/CTilesetManager.h"
#include "Layer/CLayerManager.h"

BEGIN_NAMESPACE(engine)
class CTilemap
{
private:
    CTilemapParser  m_parser;
    CTilesetManager m_tileset_manager;
    CLayerManager   m_layer_manager;

public:
    CTilemap();

    void loadMap(const char* file);
};
END_NAMESPACE

#endif // CTILEMAP_H
