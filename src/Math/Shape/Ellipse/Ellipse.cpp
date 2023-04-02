#include "Ellipse.h"

Ellipse::Ellipse(float width, float height): m_width(width), m_height(height), m_centerI(0.0f, 0.0f)
{
    m_a = width/2;
    m_b = height/2;
    m_rect = {m_centerI.getX() - m_a, m_centerI.getY() - m_b, m_width, m_height};
}

Ellipse::Ellipse(float width, float height, float x, float y): m_width(width), m_height(height)
{
    m_a = width/2;
    m_b = height/2;
    m_centerI = Point2DF(x + m_a, y + m_b);
    m_rect = {m_centerI.getX() - m_a, m_centerI.getY() - m_b, m_width, m_height};
}

const SDL_FRect &Ellipse::getRect() const
{
    return m_rect;
}

Size Ellipse::size() const
{
    return Size{m_width, m_height};
}

bool Ellipse::contain(Point2DF M)
{
    int mX, mY;
    float iX, iY;
    mX = M.getX();
    mY = M.getY();

    iX = m_centerI.getX();
    iY = m_centerI.getY();

    // expression: ((x - h)^2 / a^2) + ((y - k)^2 / b^2) = 1
    float expression = std::pow((mX - iX) / m_a, 2) + std::pow((mY - iY) / m_b, 2);

    bool condition = 0;

    condition = (std::abs(mX - iX) <= m_a) && (std::abs(mY - iY) <= m_b);    // check Point in ellipse
    condition &= (std::round(expression) == 1.0f); // check Poin in Ellipse line
    return condition;
}

Point2DF Ellipse::getPosition() const
{
    return Point2DF(m_centerI.getX() - m_a, m_centerI.getY() - m_b);
}

const char *Ellipse::getTypeName() const
{
    return "ellipse";
}

float Ellipse::acreage()
{
    return PI * m_a * m_b;
}

float Ellipse::perimeter()
{
    return 2 * PI * sqrt((m_a * m_a + m_b * m_b) / 2);
}

Point2DF Ellipse::getCenterI() const
{
    return m_centerI;
}
