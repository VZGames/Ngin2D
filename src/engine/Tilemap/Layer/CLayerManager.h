#ifndef CLAYERMANAGER_H
#define CLAYERMANAGER_H

#include <stack>
#include "CommonDefine.h"
#include "TilemapParser/tilemap_define.h"


BEGIN_NAMESPACE(engine)
class CLayerManager
{
private:
    std::vector<TmxLayer> m_layers;
public:
    CLayerManager();

    void push(TmxLayer&&);
    void update(float);
    void render();
};
END_NAMESPACE

#endif // CLAYERMANAGER_H
