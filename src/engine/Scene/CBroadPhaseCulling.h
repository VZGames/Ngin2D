#ifndef CBROADPHASECULLING_H
#define CBROADPHASECULLING_H

#include <unordered_set>
#include <CommonDefine.h>
#include "DataStructs/Grid/CGrid.h"

BEGIN_NAMESPACE(engine)
class CBroadPhaseCulling: public CGrid<std::unordered_set<uint32_t>>
{
private:
    static CBroadPhaseCulling* s_instance;
    CBroadPhaseCulling(float cellWidth, float cellHeight, int rows, int columns);
public:
    static CBroadPhaseCulling* instance(float cellWidth = 16, float cellHeight = 16, int rows = 30, int columns = 30);
    void insert(uint32_t, float x, float y);
    void clean();
};
END_NAMESPACE

#endif // CBROADPHASECULLING_H
