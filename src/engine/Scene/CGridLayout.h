#ifndef CGRIDLAYOUT_H
#define CGRIDLAYOUT_H

#include "CommonDefine.h"
#include "matrix2D.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class CGridLayout: public Matrix2D<int>
{
private:
    int hash(int x, int y);
public:
    CGridLayout(int rows, int columns);

    void insertEntity(uint32_t id, float x, float y);
    void removeEntity(uint32_t id);
};
END_NAMESPACE

#endif // CGRIDLAYOUT_H
