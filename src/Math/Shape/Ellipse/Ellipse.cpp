#include "Ellipse.h"

Ellipse::Ellipse(double a, double b): m_a(a), m_b(b), m_centerI(0, 0)
{}

Ellipse::Ellipse(double a, double b, int x, int y): m_a(a), m_b(b)
{
    m_centerI = Point2DI(x + a, y + b);
}

Size Ellipse::size() const
{
    return Size{(int)m_a * 2, (int)m_b * 2};
}

bool Ellipse::contain(Point2DI M)
{
    int mX, mY;
    double iX, iY;
    mX = (double)M.getX();
    mY = (double)M.getY();

    iX = (double)m_centerI.getX();
    iY = (double)m_centerI.getY();

    // expression: ((x - h)^2 / a^2) + ((y - k)^2 / b^2) = 1
    double expression = std::pow((mX - iX) / m_a, 2) + std::pow((mY - iY) / m_b, 2);

    bool condition = 0;

    condition = (std::abs(mX - iX) <= m_a) && (std::abs(mY - iY) <= m_b);    // check Point in ellipse
    condition &= (std::round(expression) == 1.0f); // check Poin in Ellipse line
    return condition;
}

Point2DI Ellipse::getPosition() const
{
    return Point2DI(m_centerI.getX() - m_a, m_centerI.getY() - m_b);
}

const char *Ellipse::getTypeName() const
{
    return "ellipse";
}

double Ellipse::acreage()
{
    return PI * m_a * m_b;
}

double Ellipse::perimeter()
{
    return 2 * PI * sqrt((m_a * m_a + m_b * m_b) / 2);
}

Point2DI Ellipse::getCenterI() const
{
    return m_centerI;
}
