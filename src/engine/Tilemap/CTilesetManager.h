#ifndef CTILESETMANAGER_H
#define CTILESETMANAGER_H

#include <unordered_map>
#include <CommonDefine.h>
#include "TilemapParser/TmxFormat.h"

BEGIN_NAMESPACE(engine)
class CTilesetManager
{
private:
    std::unordered_map<const char*, TmxTileSet>  m_tilesets;
public:
    CTilesetManager();

    void insert(const char*, TmxTileSet&&);
    std::unordered_map<const char*, TmxTileSet> tilesets() const;
};
END_NAMESPACE

#endif // CTILESETMANAGER_H
