#ifndef CLAYERMANAGER_H
#define CLAYERMANAGER_H

#include <stack>
#include "CommonDefine.h"
#include "CLayer.h"

BEGIN_NAMESPACE(engine)
class CLayerManager
{
private:
    std::stack<CLayer> m_layer;
public:
    CLayerManager();

    void push(CLayer);
};
END_NAMESPACE

#endif // CLAYERMANAGER_H
