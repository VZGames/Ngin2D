#ifndef CLAYERMANAGER_H
#define CLAYERMANAGER_H

#include <stack>
#include <CommonDefine.h>
#include <matrix2D.h>
#include <TilemapParser/TmxFormat.h>
#include "CLayer.h"

BEGIN_NAMESPACE(engine)
class CLayerManager
{
private:
    CLayerManager();
    static CLayerManager *s_instance;

private:
    std::vector<CLayer> m_layers; // first: raw info, second: matrix tiles

public:
    static CLayerManager *instance();
    void push(TmxLayer);
    void clear();
    std::vector<CLayer> layers() const;
};
END_NAMESPACE

#endif // CLAYERMANAGER_H
