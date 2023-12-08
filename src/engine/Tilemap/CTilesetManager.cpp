#include "CTilesetManager.h"
#include "CTexture2DManager.h"

BEGIN_NAMESPACE(engine)
CTilesetManager::CTilesetManager()
{

}

void CTilesetManager::insert(const char* name, TmxTileSet&& tileset)
{
    m_tilesets[name] = tileset;
    CTexture2DManager::instance()->loadTexture(name, tileset.image->source);
}

std::unordered_map<const char*, TmxTileSet> CTilesetManager::tilesets() const
{
    return m_tilesets;
}
END_NAMESPACE


