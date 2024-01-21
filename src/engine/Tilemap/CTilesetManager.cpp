#include "CTilesetManager.h"
#include "CTexture2DManager.h"
#include <LoggerDefines.h>

using namespace engine;
CTilesetManager *CTilesetManager::s_instance = nullptr;
CTilesetManager::CTilesetManager()
{

}

CTilesetManager::~CTilesetManager()
{
    DBG("Release Instance CTilesetManager At address [%p]", this);
}

CTilesetManager *CTilesetManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CTilesetManager(): s_instance;
}

void CTilesetManager::insert(const char* name, TmxTileSet&& tileset)
{
    m_tilesets[name] = tileset;
    CTexture2DManager::instance()->loadTexture(name, tileset.image->source);
}

void CTilesetManager::clear()
{
    m_tilesets.clear();
}

std::unordered_map<const char*, TmxTileSet> CTilesetManager::tilesets() const
{
    return m_tilesets;
}



