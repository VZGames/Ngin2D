#ifndef CLAYERMANAGER_H
#define CLAYERMANAGER_H

#include <stack>
#include "CommonDefine.h"
#include "TilemapParser/TmxFormat.h"


BEGIN_NAMESPACE(engine)
class CLayerManager
{
private:
    std::vector<TmxLayer> m_layers;
public:
    CLayerManager();

    void push(TmxLayer&&);
    std::vector<TmxLayer> layers() const;
};
END_NAMESPACE

#endif // CLAYERMANAGER_H
