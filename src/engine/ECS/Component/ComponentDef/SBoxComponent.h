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
    SBoxComponent(E_BODY_TYPE bodyType, float x, float y, float width, float height):
        CComponent(__FUNCTION__),
        body(bodyType),
        size{width, height}
    {
        shape.setX(x);
        shape.setY(y);
    }

    void setVertex(Vector2DF vertex)
    {
        vertex.x += shape.x();
        vertex.y += shape.y();
        shape.pushVertex(vertex);
    }

    void updateVertex(Vector2DF &vertex)
    {
        vertex.x += shape.x();
        vertex.y += shape.y();
    }
    void update(float x, float y)
    {
        shape.clearAxis();
        shape.setX(x);
        shape.setY(y);
        int count = static_cast<int>(shape.vertices().size());
        for(int i = 0; i < count - 1; i++)
        {
            Vector2DF vertexA = shape.vertexAt((i + 1) % count);
            Vector2DF vertexB = shape.vertexAt(i);
            updateVertex(vertexA);
            updateVertex(vertexB);

            Vector2DF edge =  static_cast<Vector2D<float>>(vertexA) - static_cast<Vector2D<float>>(vertexB);
            Vector2DF normal = edge.normalize().perp();
            normal.print();
            shape.pushAxis(normal);
        }
    }

    E_BODY_TYPE body;
    Size2D<float> size;
    CPolygonShape shape;
};
END_NAMESPACE

#endif // SBOXCOMPONENT_H
