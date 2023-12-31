#ifndef CGRIDLAYOUT_H
#define CGRIDLAYOUT_H

#include <stack>
#include <CommonDefine.h>
#include "DataStructs/Grid/CGrid.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class CGridLayout: public CGrid<std::stack<int>>
{
public:
    CGridLayout(float cellwith, int rows, int columns);


    void insertTileForLayer(int tileId, float x, float y);
};
END_NAMESPACE

#endif // CGRIDLAYOUT_H
