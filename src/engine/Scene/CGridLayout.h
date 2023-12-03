#ifndef CGRIDLAYOUT_H
#define CGRIDLAYOUT_H

#include <unordered_set>
#include "CommonDefine.h"
#include "DataStructs/Grid/CGrid.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class CGridLayout: public CGrid<int>
{
public:
    CGridLayout(float cellwith, int rows, int columns);
};
END_NAMESPACE

#endif // CGRIDLAYOUT_H
