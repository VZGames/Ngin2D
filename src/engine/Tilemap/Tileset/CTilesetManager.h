#ifndef CTILESETMANAGER_H
#define CTILESETMANAGER_H

#include "CommonDefine.h"
#include "CTileset.h"

BEGIN_NAMESPACE(engine)
class CTilesetManager
{
private:
    std::vector<CTileset>  m_tiles;
public:
    CTilesetManager();

    void insert();
};
END_NAMESPACE

#endif // CTILESETMANAGER_H
