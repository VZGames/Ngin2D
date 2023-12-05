#include "CTilesetManager.h"

BEGIN_NAMESPACE(engine)
CTilesetManager::CTilesetManager()
{

}

void CTilesetManager::insert(TmxTileSet&& tileset)
{
    m_tilesets.push_back(tileset);
}

END_NAMESPACE

