#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Math/Shape/IShape.h"
#include "Math/math2D.h"

class Rectangle : public IShape
{
public:
    Rectangle(double width, double height);
    Rectangle(double width, double height, int x, int y);

    // IShape interface
public:
    virtual Size size() const override;
    virtual Point2DI getPosition() const override;
    virtual const char *getTypeName() const override;
    virtual bool contain(Point2DI point) override;
    virtual double acreage() override;
    virtual double perimeter() override;

private:
    double m_width, m_height;
    int m_x, m_y;
};

#endif // RECTANGLE_H
