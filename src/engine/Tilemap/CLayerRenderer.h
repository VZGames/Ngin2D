#ifndef CLAYERRENDERER_H
#define CLAYERRENDERER_H

#include <stack>
#include "CommonDefine.h"
#include "TilemapParser/TmxFormat.h"


BEGIN_NAMESPACE(engine)
class CLayerRenderer
{
public:
    CLayerRenderer();

    void render(TmxLayer&);
};
END_NAMESPACE

#endif // CLAYERRENDERER_H
