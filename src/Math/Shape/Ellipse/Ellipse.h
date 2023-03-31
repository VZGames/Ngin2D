#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Math/Shape/IShape.h"
#include "Math/math2D.h"

class Ellipse: public IShape
{
public:
    Ellipse(double a, double b);

    bool contain(Point2DI M);

    // IShape interface
public:
    virtual double acreage() override;
    virtual double perimeter() override;

private:
    Point2DI I;
    double a, b;
};

#endif // ELLIPSE_H
