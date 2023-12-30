#ifndef COBJECTLAYERMANAGER_H
#define COBJECTLAYERMANAGER_H

#include "CommonDefine.h"
#include "TilemapParser/TmxFormat.h"

BEGIN_NAMESPACE(engine)
class CObjectLayerManager
{
private:
    std::vector<TmxObject> m_objects;
public:
    CObjectLayerManager();

    void push(TmxObject&&);
    std::vector<TmxObject> objects() const;
};
END_NAMESPACE

#endif // COBJECTLAYERMANAGER_H
