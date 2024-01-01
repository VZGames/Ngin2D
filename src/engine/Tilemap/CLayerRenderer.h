#ifndef CLAYERRENDERER_H
#define CLAYERRENDERER_H

#include <stack>
#include <unordered_map>
#include <CommonDefine.h>
#include "matrix2D.h"
#include "TilemapParser/TmxFormat.h"

BEGIN_NAMESPACE(engine)
class CLayerRenderer
{
public:
    CLayerRenderer();

    void render(const std::unordered_map<const char*, TmxTileSet> &, TmxLayer &, Matrix2D<int>&);
};
END_NAMESPACE

#endif // CLAYERRENDERER_H
