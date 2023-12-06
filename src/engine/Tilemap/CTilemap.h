#ifndef CTILEMAP_H
#define CTILEMAP_H

#include <stack>
#include "CommonDefine.h"
#include "TilemapParser/CTilemapParser.h"
#include "CTilesetManager.h"
#include "CLayerManager.h"
#include "CLayerRenderer.h"

BEGIN_NAMESPACE(engine)
class CTilemap
{
private:
    CTilemapParser  m_parser;
    CTilesetManager m_tileset_manager;
    CLayerManager   m_layer_manager;
    CLayerRenderer  m_layer_renderer;

public:
    CTilemap();

    void loadMap(const char* file);
    void update(float dt);
    void render();
};
END_NAMESPACE

#endif // CTILEMAP_H
