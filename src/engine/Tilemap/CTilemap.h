#ifndef CTILEMAP_H
#define CTILEMAP_H

#include <stack>
#include "CommonDefine.h"
#include "DataStructs/Grid/CGrid.h"
#include "TilemapParser/CTilemapParser.h"

BEGIN_NAMESPACE(engine)
class CTilemap: public CGrid<std::stack<int>>
{
private:
    CTilemapParser m_parser;

public:
    CTilemap();

    void loadMap(const char* file);
};
END_NAMESPACE

#endif // CTILEMAP_H
