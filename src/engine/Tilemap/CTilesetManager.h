#ifndef CTILESETMANAGER_H
#define CTILESETMANAGER_H

#include <unordered_map>
#include <CommonDefine.h>
#include <TilemapParser/TmxFormat.h>

BEGIN_NAMESPACE(engine)
class CTilesetManager
{
private:
    CTilesetManager();
    static CTilesetManager *s_instance;

private:
    std::unordered_map<const char*, TmxTileSet>  m_tilesets;

public:
    static CTilesetManager *instance();
    void insert(const char*, TmxTileSet&&);
    void clear();
    std::unordered_map<const char*, TmxTileSet> tilesets() const;
};
END_NAMESPACE

#endif // CTILESETMANAGER_H
