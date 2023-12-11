#ifndef CTILEMAP_H
#define CTILEMAP_H

#include <stack>
#include "CommonDefine.h"
#include "TilemapParser/CTilemapParser.h"
#include "CTilesetManager.h"
#include "CLayerManager.h"
#include "CLayerRenderer.h"
#include "ThreadPool/CThreadPool.h"

BEGIN_NAMESPACE(engine)
class CTilemap
{
private:
    CTilemapParser  m_parser;
    CTilesetManager m_tileset_manager;
    CLayerManager   m_layer_manager;
    CLayerRenderer  m_layer_renderer;
    TmxMap          *m_map;
    CThreadPool     *m_pool;

public:
    CTilemap();
    ~CTilemap();

    void loadMap(const char* file);
    void update(float dt);
    void render();

    TmxMap *map() const;
};
END_NAMESPACE

#endif // CTILEMAP_H
