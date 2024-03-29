#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Math/Shape/IShape.h"
#include "Math/math2D.h"

class Ellipse: public IShape
{
public:
    Ellipse(float a, float b);
    Ellipse(float a, float b, float x, float y);

    void findIntersectWithLine(Point2DF B);

    // IShape interface
public:
    virtual bool contain(Point2DF M) override;
    virtual float acreage() override;
    virtual float perimeter() override;
    

    const float &radiusX() const;
    const float &radiusY() const;

private:

    float m_width, m_height;
    float m_a, m_b;

};

#endif // ELLIPSE_H
