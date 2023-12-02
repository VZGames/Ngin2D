#include "COriginLevel.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(script)
COriginLevel::COriginLevel()
{
    m_name = __FUNCTION__;
    m_parser.loadFile("./debug/assets/Maps/PhuHoa.tmx");

    std::vector<TmxTileSet>         tilesets(m_parser.countWith("tileset"));
    std::vector<TmxLayer>           layers(m_parser.countWith("layer"));

    TmxTileSet tileset;
    for(int i = 0; i < static_cast<int>(tilesets.size()); i++)
    {
        m_parser.parse(i, tileset);
        tilesets[i] = std::move(tileset);
    }

    TmxLayer layer;
    for(int i = 0; i < static_cast<int>(layers.size()); i++)
    {
        m_parser.parse(i, layer);
        layers[i] = std::move(layer);

        Matrix2D<int> matrix = Matrix2D<int>::fromString(layers[i].data->content, layer.height, layer.width);
        m_layers.emplace_back(matrix);
        m_layers.back().print();
    }
}

void COriginLevel::update(float)
{

}

void COriginLevel::render()
{

}
END_NAMESPACE

