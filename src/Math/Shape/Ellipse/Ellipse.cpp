#include "Ellipse.h"

Ellipse::Ellipse(double a, double b): a(a), b(b)
{}

Ellipse::Ellipse(double a, double b, int x, int y): a(a), b(b)
{
    I = Point2DI(x + a, y + b);
}

bool Ellipse::contain(Point2DI M)
{
    int mX, mY;
    double iX, iY;
    mX = (double)M.getX();
    mY = (double)M.getY();

    iX = (double)I.getX();
    iY = (double)I.getY();

    // expression: ((x - h)^2 / a^2) + ((y - k)^2 / b^2) = 1
    return (std::ceil(std::pow((mX - iX), 2) / (a * a) + std::pow((mY - iY), 2) / (b * b)) == 1.0f);
}

double Ellipse::acreage()
{
    return PI * a * b;
}

double Ellipse::perimeter()
{
    return 2 * PI * sqrt((a * a + b * b) / 2);
}
