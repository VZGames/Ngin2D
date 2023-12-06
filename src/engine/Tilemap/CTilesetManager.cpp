#include "CTilesetManager.h"

BEGIN_NAMESPACE(engine)
CTilesetManager::CTilesetManager()
{

}

void CTilesetManager::insert(TmxTileSet&& tileset)
{
    m_tilesets.push_back(tileset);
}

std::vector<TmxTileSet> CTilesetManager::tilesets() const
{
    return m_tilesets;
}
END_NAMESPACE


