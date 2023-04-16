#include "Ellipse.h"

Ellipse::Ellipse(float width, float height): m_width(width), m_height(height)
{
    m_a = width/2;
    m_b = height/2;
    m_x = 0.0f;
    m_y = 0.0f;
    m_center = Point2DF(m_x + m_a, m_y + m_b);
    m_rect ={m_center.getX() - m_a, m_center.getY() - m_b, m_width, m_height};
    m_size = SizeF {m_width, m_height};
    m_position = Point2DF(m_center.getX() - m_a, m_center.getY() - m_b);
}

Ellipse::Ellipse(float width, float height, float x, float y): m_width(width), m_height(height)
{
    m_a = width/2;
    m_b = height/2;
    m_x = x;
    m_y = y;
    m_center = Point2DF(m_x + m_a, m_y + m_b);
    m_rect ={m_center.getX() - m_a, m_center.getY() - m_b, m_width, m_height};
    m_size = SizeF {m_width, m_height};
    m_position = Point2DF(m_center.getX() - m_a, m_center.getY() - m_b);
}

bool Ellipse::contain(Point2DF M)
{
    int mX, mY;
    float iX, iY;
    mX = M.getX();
    mY = M.getY();

    iX = m_center.getX();
    iY = m_center.getY();
    // expression: ((x - h)^2 / a^2) + ((y - k)^2 / b^2) = 1
    float expression = std::pow((mX - iX) / m_a, 2) + std::pow((mY - iY) / m_b, 2);

    bool condition = (std::round(expression) == 1.0f); // check Poin in Ellipse line
    return condition;
}

const char *Ellipse::type() const
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


const float &Ellipse::radiusX() const
{
    return m_a;
}

const float &Ellipse::radiusY() const
{
    return m_b;
}
