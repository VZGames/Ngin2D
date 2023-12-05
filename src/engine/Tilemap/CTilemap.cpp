#include "CTilemap.h"

BEGIN_NAMESPACE(engine)
CTilemap::CTilemap()
{

}

void CTilemap::loadMap(const char *file)
{
    m_parser.loadFile(file);

    int tilesetNum = 0;
    int layerNum   = 0;

    tilesetNum = m_parser.countWith("tileset");
    layerNum   = m_parser.countWith("layer");

    for(int i = 0; i < tilesetNum; i++)
    {
        TmxTileSet tmxTileset;
        m_parser.parse(i, tmxTileset);
        m_tileset_manager.insert(std::move(tmxTileset));
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
    m_layer_manager.update(dt);
}


void CTilemap::render()
{
    m_layer_manager.render();
}

END_NAMESPACE

