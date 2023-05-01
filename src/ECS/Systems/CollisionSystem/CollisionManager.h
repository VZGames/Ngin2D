#ifndef COLLISION_H
#define COLLISION_H

#include "Math/math2D.h"
#include "Math/Shape/IShape.h"
#include "Math/Shape/Shapes.h"

class CollisionManager
{
public:
    CollisionManager();
    bool IntersectCircles(Circle *A, Circle *B);
    bool IntersectCurvePolygon(Ellipse* A, Polygon *B);
    bool IntersectPolygons(Polygon* A, Polygon *B);

    const Vector2DF &mtv() const;

private:
    Vector2DF m_mtv;
    float m_minGap;
};

#endif // COLLISION_H
