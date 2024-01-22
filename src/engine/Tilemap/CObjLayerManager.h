#ifndef COBJLAYERMANAGER_H
#define COBJLAYERMANAGER_H

#include <CommonDefine.h>
#include <TilemapParser/TmxFormat.h>
#include "Geometry/CPolygonShape.h"

BEGIN_NAMESPACE(engine)
class CBroadPhaseCulling;
class CObjLayerManager
{
private:
    std::vector<TmxObject>          m_objects;
    std::vector<CPolygonShape>      m_box;
public:
    CObjLayerManager();

    void push(TmxObject&&);
    const std::vector<TmxObject> *objects() const;
    const std::vector<CPolygonShape> *box() const;
    //    bool checkCollision(AShape*, Vector2D<float> &);
};
END_NAMESPACE

#endif // COBJLAYERMANAGER_H
