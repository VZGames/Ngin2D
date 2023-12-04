#include "CTilemap.h"

BEGIN_NAMESPACE(engine)
CTilemap::CTilemap()
{

}

void CTilemap::loadMap(const char *file)
{
    m_parser.loadFile(file);

    int mapWidth = m_parser.map().width;
    int mapHeight = m_parser.map().height;

    int tilesetNum = 0;
    int layerNum   = 0;

    tilesetNum = m_parser.countWith("tileset");
    layerNum   = m_parser.countWith("layer");

    std::vector<TmxTileSet>         tilesets(tilesetNum);
    std::vector<TmxLayer>           layers(layerNum);

    TmxTileSet tileset;
    TmxLayer layer;

    for(int i = 0; i < static_cast<int>(tilesets.size()); i++)
    {
        m_parser.parse(i, tileset);
        tilesets[i] = std::move(tileset);
    }

    for(int i = 0; i < static_cast<int>(layers.size()); i++)
    {
        m_parser.parse(i, layer);
        layers[i] = std::move(layer);

        Matrix2D<int> matrix = Matrix2D<int>::fromString(layers[i].data->content, layer.height, layer.width);

        for(int r = 0; r < layer.height; r++)
        {
            for(int c = 0; c < layer.width; c++)
            {
//                m_grid_layout.insertTileForLayer(matrix.at(r, c), layer.x, layer.y);
            }
        }
    }


}
END_NAMESPACE


