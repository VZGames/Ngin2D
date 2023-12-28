#include "CTilemap.h"
#include "Camera/CCameraSys.h"

BEGIN_NAMESPACE(engine)
CTilemap *CTilemap::s_instance = nullptr;
CTilemap::CTilemap()
{
}

CTilemap::~CTilemap()
{
    m_pool->shutdown();
}

CTilemap *CTilemap::instance()
{
    return s_instance = (s_instance == nullptr)? new CTilemap(): s_instance;
}

void CTilemap::loadMap(const char *file)
{
    m_parser.loadFile(file);
    m_map = &m_parser.map();

    float scale = CCameraSys::instance()->scale();

    m_coord_limit.x = m_map->width * m_map->tile_width * scale;
    m_coord_limit.y = m_map->height * m_map->tile_height * scale;

    int tilesetNum = 0;
    int layerNum   = 0;
    int objectNum  = 0;

    tilesetNum = m_parser.countWith("tileset");
    layerNum   = m_parser.countWith("layer");
    objectNum  = m_parser.countWith("objectgroup.object");

    m_pool = new CThreadPool(layerNum);
    m_pool->init();

    for(int i = 0; i < tilesetNum; i++)
    {
        TmxTileSet tmxTileset;
        m_parser.parse(i, tmxTileset);
        m_tileset_manager.insert(tmxTileset.name, std::move(tmxTileset));
    }

    for(int i = 0; i < layerNum; i++)
    {
        TmxLayer tmxLayer;
        m_parser.parse(i, tmxLayer);
        m_layer_manager.push(std::move(tmxLayer));
    }

    for(int i = 0; i < objectNum; i++)
    {
        TmxObject tmxObject;
        m_parser.parse(i, tmxObject);
    }

}

void CTilemap::update(float dt)
{
    UNUSED(dt)
    float scale = CCameraSys::instance()->scale();

    // update coord_limit if scale changed
    m_coord_limit.x = m_map->width * m_map->tile_width * scale;
    m_coord_limit.y = m_map->height * m_map->tile_height * scale;
    // -------------------------------------

    Offset *offset = CCameraSys::instance()->offset();

    for(auto &data: m_layer_manager.layers())
    {
        data.first.offset_x = offset->x;
        data.first.offset_y = offset->y;
    }
}


void CTilemap::render()
{
    for(auto &data: m_layer_manager.layers())
    {
        m_pool->submit([&]() {
            m_layer_renderer.render(m_tileset_manager.tilesets(), data.first, std::move(data.second));
        }).get();
    }
}

TmxMap *CTilemap::map() const
{
    return m_map;
}

Vector2D<float> CTilemap::coord_limit() const
{
    return m_coord_limit;
}
END_NAMESPACE





