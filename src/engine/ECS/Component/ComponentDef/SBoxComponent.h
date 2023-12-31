#ifndef SBOXCOMPONENT_H
#define SBOXCOMPONENT_H

#include <CommonDefine.h>
#include "Component/CComponent.h"
#include "Geometry/CPolygonShape.h"
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
        shape.setBox();
    }

    void setVertex(float x, float y)
    {
        shape.pushVertex(x, y);
    }

    std::vector<Vector2D<float>> vertices()
    {
        return shape.vertices();
    }

    void setAxes()
    {
        shape.clearAxis();
        int count = static_cast<int>(shape.vertices().size());
        for(int i = 0; i < count - 1; i++)
        {
            Vector2D<float> vertexA = shape.vertexAt(i);
            Vector2D<float> vertexB = shape.vertexAt((i + 1) % count);
            Vector2D<float> edge =  static_cast<Vector2D<float>>(vertexB) - static_cast<Vector2D<float>>(vertexA);
            Vector2D<float> normal = edge.normalize().perp();
            shape.pushAxis(normal);
        }
    }

    void update(Vector2D<float> *position)
    {
        shape.updatePosition(position->x, position->y);
        setAxes();
    }

    E_BODY_TYPE body;
    CPolygonShape shape;
};
END_NAMESPACE

#endif // SBOXCOMPONENT_H
