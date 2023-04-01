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
    virtual Size size() const override;
    virtual bool contain(Point2DI M) override;
    virtual Point2DI getPosition() const override;
    virtual const char *getTypeName() const override;
    virtual double acreage() override;
    virtual double perimeter() override;

    Point2DI getCenterI() const;

private:
    Point2DI m_centerI;
    double m_a, m_b;
};

#endif // ELLIPSE_H
