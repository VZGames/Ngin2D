#ifndef COBJECTLAYERMANAGER_H
#define COBJECTLAYERMANAGER_H

#include <CommonDefine.h>
#include <TilemapParser/TmxFormat.h>
#include "Geometry/CPolygonShape.h"

BEGIN_NAMESPACE(engine)
class CBroadPhaseCulling;
class CObjectLayerManager
{
private:
    std::vector<TmxObject>          m_objects;
    std::vector<CPolygonShape>      m_box;
    CBroadPhaseCulling              *m_broad_phase_culling;
    public : CObjectLayerManager();

    void push(TmxObject&&);
    const std::vector<TmxObject> *objects() const;
    const std::vector<CPolygonShape> *box() const;
    bool checkCollision(AShape*, Vector2D<float> &);
};
END_NAMESPACE

#endif // COBJECTLAYERMANAGER_H
