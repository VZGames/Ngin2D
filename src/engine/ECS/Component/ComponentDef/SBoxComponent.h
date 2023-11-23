#ifndef SBOXCOMPONENT_H
#define SBOXCOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"
#include "CPolygonShape.h"
#include "vector2D.h"
#include "size2D.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(engine)
class CEntity;
struct SBoxComponent: public CComponent
{
    SBoxComponent(float x, float y, float width, float height):
        CComponent(__FUNCTION__),
        size{width, height}
    {
        shape.setX(x);
        shape.setY(y);
    }

    template<typename ..._Vertex>
    void setVertices(_Vertex&&...vertex)
    {
        (shape.pushVertex(std::forward<_Vertex>(vertex)), ...);
    }

    void update(float x, float y)
    {
        shape.setX(x);
        shape.setY(y);
        shape.clearAxis();
        int count = static_cast<int>(shape.vertices().size());
        for(int i = 0; i < count - 1; i++)
        {
            Vector2DF vertexA = shape.vertexAt((i + 1) % count);
            Vector2DF vertexB = shape.vertexAt(i);
            Vector2DF edge =  static_cast<Vector2D<float>>(vertexB) - static_cast<Vector2D<float>>(vertexA);
            Vector2DF normal = edge.normalize().perp();
//            normal.print();
            shape.pushAxis(normal);
        }
    }
    Size2D<float> size;
    CPolygonShape shape;
};
END_NAMESPACE

#endif // SBOXCOMPONENT_H
