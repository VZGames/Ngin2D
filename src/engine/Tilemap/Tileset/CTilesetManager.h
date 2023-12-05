#ifndef CTILESETMANAGER_H
#define CTILESETMANAGER_H

#include "CommonDefine.h"
#include "TilemapParser/tilemap_define.h"

BEGIN_NAMESPACE(engine)
class CTilesetManager
{
private:
    std::vector<TmxTileSet>  m_tilesets;
public:
    CTilesetManager();

    void insert(TmxTileSet&&);
};
END_NAMESPACE

#endif // CTILESETMANAGER_H
