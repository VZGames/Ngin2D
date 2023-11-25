#ifndef SBOXCOMPONENT_H
#define SBOXCOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"
#include "CPolygonShape.h"
#include "vector2D.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(engine)
class CEntity;
struct SBoxComponent: public CComponent
{
    SBoxComponent(E_BODY_TYPE bodyType, float x, float y):
        CComponent(__FUNCTION__),
        body(bodyType)
    {
        shape.setX(x);
        shape.setY(y);
    }

    void setVertex(Vector2DF vertex)
    {
        shape.pushVertex(vertex);
    }

    std::vector<Vector2DF> vertices()
    {
        return shape.vertices();
    }

    void setAxes()
    {
        int count = static_cast<int>(shape.vertices().size());
        for(int i = 0; i < count - 1; i++)
        {
            Vector2DF vertexA = shape.vertexAt(i);
            Vector2DF vertexB = shape.vertexAt((i + 1) % count);
            Vector2DF edge =  static_cast<Vector2D<float>>(vertexB) - static_cast<Vector2D<float>>(vertexA);
            Vector2DF normal = edge.normalize().perp();
            shape.pushAxis(normal);
        }
    }

    void update(Vector2DF *position)
    {
        shape.updatePosition(position->x, position->y);
    }

    E_BODY_TYPE body;
    CPolygonShape shape;
};
END_NAMESPACE

#endif // SBOXCOMPONENT_H
