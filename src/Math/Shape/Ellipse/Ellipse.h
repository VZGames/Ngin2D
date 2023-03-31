#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Math/Shape/IShape.h"
#include "Math/math2D.h"

class Ellipse: public IShape
{
public:
    Ellipse(double a, double b);
    Ellipse(double a, double b, int x, int y);

    // IShape interface
public:
    virtual bool contain(Point2DI M) override;
    virtual double acreage() override;
    virtual double perimeter() override;

private:
    Point2DI I;
    double a, b;
};

#endif // ELLIPSE_H
