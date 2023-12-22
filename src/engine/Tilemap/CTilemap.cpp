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

    m_coord_limit.x = m_map->width * m_map->tile_width;
    m_coord_limit.y = m_map->height * m_map->tile_height;

    int tilesetNum = 0;
    int layerNum   = 0;

    tilesetNum = m_parser.countWith("tileset");
    layerNum   = m_parser.countWith("layer");

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

}

void CTilemap::update(float dt)
{
    UNUSED(dt)
    // update coord_limit if scale changed
    m_coord_limit.x = m_map->width * m_map->tile_width;
    m_coord_limit.y = m_map->height * m_map->tile_height;
    // -------------------------------------

    Offset *camera_offset = CCameraSys::instance()->offset();
    Offset map_offset(camera_offset->x, camera_offset->y);

//    if(camera_offset->x < 0)
//    {
//        map_offset.x = 0;
//    }
//    if(camera_offset->y < 0)
//    {
//        map_offset.y = 0;
//    }
//    if(camera_offset->x > m_coord_limit.x  - 640)
//    {
//        map_offset.x = m_coord_limit.x - 640;
//    }
//    if(camera_offset->y > m_coord_limit.y - 640)
//    {
//        map_offset.y = m_coord_limit.y - 640;
//    }

    for(auto &data: m_layer_manager.layers())
    {
//        data.first.offset_x = map_offset.x;
//        data.first.offset_y = map_offset.y;

//        data.first.x -= data.first.offset_x;
//        data.first.y -= data.first.offset_y;
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





