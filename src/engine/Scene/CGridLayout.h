#ifndef CGRIDLAYOUT_H
#define CGRIDLAYOUT_H

#include "CommonDefine.h"
#include "matrix2D.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class CGridLayout: public Matrix2D<int>
{
public:
    CGridLayout(int rows, int columns);

    void insertEntity(CEntity* entity);
    void removeEntity(CEntity* entity);
};
END_NAMESPACE

#endif // CGRIDLAYOUT_H
