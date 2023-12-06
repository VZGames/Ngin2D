#ifndef CTILESETMANAGER_H
#define CTILESETMANAGER_H

#include "CommonDefine.h"
#include "TilemapParser/TmxFormat.h"

BEGIN_NAMESPACE(engine)
class CTilesetManager
{
private:
    std::vector<TmxTileSet>  m_tilesets;
public:
    CTilesetManager();

    void insert(TmxTileSet&&);
    std::vector<TmxTileSet> tilesets() const;
};
END_NAMESPACE

#endif // CTILESETMANAGER_H
