#ifndef SBOXCOMPONENT_H
#define SBOXCOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"
#include "CPolygonShape.h"
#include "vector2D.h"
#include "size2D.h"
#include "LoggerDefines.h"
#include "CCamera.h"
#include "offset2D.h"

BEGIN_NAMESPACE(engine)
class CEntity;
struct SBoxComponent: public CComponent
{
    SBoxComponent(E_BODY_TYPE bodyType, float x, float y, float width, float height):
        CComponent(__FUNCTION__),
        body(bodyType)
    {
        float scale = CCamera::instance()->scale();
        size = {width * scale, height * scale};
        shape.setX(x);
        shape.setY(y);
    }

    void setVertex(Vector2DF vertex)
    {
        vertex.x += shape.x();
        vertex.y += shape.y();
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

    void update(Offset offset)
    {
        shape.updatePosition(offset.getX(), offset.getY());
    }

    E_BODY_TYPE body;
    Size2D<float> size;
    CPolygonShape shape;
};
END_NAMESPACE

#endif // SBOXCOMPONENT_H
