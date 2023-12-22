#ifndef CTILEMAP_H
#define CTILEMAP_H

#include <stack>
#include "CommonDefine.h"
#include "TilemapParser/CTilemapParser.h"
#include "CTilesetManager.h"
#include "CLayerManager.h"
#include "CLayerRenderer.h"
#include "ThreadPool/CThreadPool.h"
#include "vector2D.h"

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

    Vector2D<float> m_coord_limit;

private:
    CTilemap();
    ~CTilemap();
    static CTilemap *s_instance;

public:
    static CTilemap *instance();
    void loadMap(const char* file);
    void update(float dt);
    void render();

    TmxMap *map() const;
    Vector2D<float> coord_limit() const;
};
END_NAMESPACE

#endif // CTILEMAP_H
