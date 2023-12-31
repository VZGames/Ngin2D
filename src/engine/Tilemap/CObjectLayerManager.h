#ifndef COBJECTLAYERMANAGER_H
#define COBJECTLAYERMANAGER_H

#include <CommonDefine.h>
#include "TilemapParser/TmxFormat.h"
#include "Geometry/CPolygonShape.h"

BEGIN_NAMESPACE(engine)
class CObjectLayerManager
{
private:
    std::vector<TmxObject> m_objects;
    std::vector<CPolygonShape> m_box;
public:
    CObjectLayerManager();

    void push(TmxObject&&);
    const std::vector<TmxObject> *objects() const;
    const std::vector<CPolygonShape> *box() const;
};
END_NAMESPACE

#endif // COBJECTLAYERMANAGER_H
