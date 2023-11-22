#ifndef SBOXCOMPONENT_H
#define SBOXCOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"
#include "CPolygonShape.h"
#include "point2D.h"
#include "vector2D.h"
#include "size2D.h"

BEGIN_NAMESPACE(engine)
class CEntity;
struct SBoxComponent: public CComponent
{
    SBoxComponent(float x, float y, float width, float height):
        CComponent(__FUNCTION__),
        size{width, height},
        position(x, y)
    {
    }

    template<typename ..._Vertex>
    void setVertices(_Vertex&&...vertex)
    {
        (vertices.push_back(std::forward<_Vertex>(vertex)), ...);
    }

    Size2D<float> size;
    Point2DF position;
    CPolygonShape shape;
    std::vector<Vector2DF> vertices;
};
END_NAMESPACE

#endif // SBOXCOMPONENT_H
