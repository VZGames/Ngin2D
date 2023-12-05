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

//        Matrix2D<int> matrix = Matrix2D<int>::fromString(layers[i].data->content, tmxLayer.height, tmxLayer.width);

//        for(int r = 0; r < matrix.rows(); r++)
//        {
//            for(int c = 0; c < matrix.columns(); c++)
//            {
////                m_grid_layout.insertTileForLayer(matrix.at(r, c), layer.x, layer.y);
//            }
//        }
    }


}
END_NAMESPACE


