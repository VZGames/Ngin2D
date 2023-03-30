#include "Ellipse.h"
#include <cmath>
Ellipse::Ellipse(double a, double b): a(a), b(b)
{}

bool Ellipse::contain(Point2DI M)
{
    int mX, mY;
    int iX, iY;
    mX = (double)M.getX();
    mY = (double)M.getY();

    iX = (double)I.getX();
    iY = (double)I.getY();

    // expression
    return (std::pow((mX - iX), 2) / (a * a) + std::pow((mY - iY), 2) / (b * b) == 1);
}

double Ellipse::acreage()
{
    return PI * a * b;
}

double Ellipse::perimeter()
{
    return 2 * PI * sqrt((a * a + b * b) / 2);
}
