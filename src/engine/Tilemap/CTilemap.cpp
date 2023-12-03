#include "CTilemap.h"

BEGIN_NAMESPACE(engine)
CTilemap::CTilemap() :CGrid<std::stack<int>>(16, 16, 100, 100)
{

}

void CTilemap::loadMap(const char *file)
{
    m_parser.loadFile(file);

    int mapWidth = m_parser.map().width;
    int mapHeight = m_parser.map().height;

    this->resize(mapHeight, mapWidth);
}
END_NAMESPACE


