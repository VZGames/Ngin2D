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
    SBoxComponent(float &x, float &y, float width, float height):
        CComponent(__FUNCTION__),
        x{x},
        y{y},
        size{width, height}
    {
    }

    template<typename ..._Vertex>
    void setVertices(_Vertex&&...vertex)
    {
        (shape.pushVertex(std::forward<_Vertex>(vertex)), ...);
        int count = static_cast<int>(shape.vertices().size());
        for(int i = 0; i < count; i++)
        {
            Vector2DF directionVector ;
            if(i + 1 == count)
            {
                directionVector = Vector2D<float>(shape.vertexAt(i)) -  Vector2D<float>(shape.vertexAt(0));
            }
            else
            {
                directionVector = Vector2D<float>(shape.vertexAt(i + 1)) -  Vector2D<float>(shape.vertexAt(i));
            }
            directionVector += Vector2DF(x, y);
            Vector2DF normalVector = directionVector.perp();
            shape.pushAxis(normalVector);
        }
    }
    float &x;
    float &y;
    Size2D<float> size;
    CPolygonShape shape;
};
END_NAMESPACE

#endif // SBOXCOMPONENT_H
