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
    CLayerManager();
    static CLayerManager *s_instance;

private:
    std::vector<std::pair<TmxLayer, Matrix2D<int>>> m_layers; // first: raw info, second: matrix tiles

public:
    static CLayerManager *instance();
    void push(TmxLayer&&);
    void clear();
    std::vector<std::pair<TmxLayer, Matrix2D<int>>> &layers();
};
END_NAMESPACE

#endif // CLAYERMANAGER_H
