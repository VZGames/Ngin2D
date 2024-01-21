#ifndef CLAYERMANAGER_H
#define CLAYERMANAGER_H

#include <CommonDefine.h>
#include <matrix2D.h>
#include <TilemapParser/TmxFormat.h>
#include "CLayer.h"

BEGIN_NAMESPACE(engine)
class CLayerManager
{
private:
    CLayerManager();

private:
    static CLayerManager    *s_instance;
    std::vector<CLayer*>     m_layers;

public:
    ~CLayerManager();
    static CLayerManager *instance();
    void push(TmxLayer&&);
    void clear();
    std::vector<CLayer*> layers();
};
END_NAMESPACE

#endif // CLAYERMANAGER_H
