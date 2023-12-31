#ifndef CLAYERMANAGER_H
#define CLAYERMANAGER_H

#include <stack>
#include <CommonDefine.h>
#include "TilemapParser/TmxFormat.h"
#include "matrix2D.h"

BEGIN_NAMESPACE(engine)
class CLayerManager
{
private:
    std::vector<std::pair<TmxLayer, Matrix2D<int>>> m_layers; // first: raw info, second: matrix tiles
public:
    CLayerManager();

    void push(TmxLayer&&);
    std::vector<std::pair<TmxLayer, Matrix2D<int>>> &layers();
};
END_NAMESPACE

#endif // CLAYERMANAGER_H
