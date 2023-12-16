#include "CTilemap.h"
#include "Camera/CCameraSys.h"

BEGIN_NAMESPACE(engine)
CTilemap::CTilemap()
{
}

CTilemap::~CTilemap()
{
    m_pool->shutdown();
}

void CTilemap::loadMap(const char *file)
{
    m_parser.loadFile(file);
    m_map = &m_parser.map();

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

    Offset offset = CCameraSys::instance()->offset();

    for(auto &data: m_layer_manager.layers())
    {
        data.first.offset_x = offset.x;
        data.first.offset_y = offset.y;

//        data.first.offset_x *= dt;
//        data.first.offset_y *= dt;

        data.first.x -= data.first.offset_x;
        data.first.y -= data.first.offset_y;
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
END_NAMESPACE



