#include "Ellipse.h"

Ellipse::Ellipse(float width, float height): m_width(width), m_height(height)
{
    m_type = TYPE_SHAPE::ELLIPSE;
    m_a = height/2;
    m_b = width/2;
    m_x = 0.0f;
    m_y = 0.0f;
    m_center = Point2DF(m_x + m_b, m_y + m_a);
    m_rect ={m_center.getX() - m_b, m_center.getY() - m_a, m_width, m_height};
    m_size = SizeF {m_width, m_height};
    m_position = Point2DF(m_center.getX() - m_b, m_center.getY() - m_a);
}

Ellipse::Ellipse(float width, float height, float x, float y): m_width(width), m_height(height)
{
    m_type = TYPE_SHAPE::ELLIPSE;
    m_a = height/2;
    m_b = width/2;
    m_x = x;
    m_y = y;
    m_center = Point2DF(m_x + m_b, m_y + m_a);
    m_rect ={m_center.getX() - m_b, m_center.getY() - m_a, m_width, m_height};
    m_size = SizeF {m_width, m_height};
    m_position = Point2DF(m_center.getX() - m_b, m_center.getY() - m_a);
}

void Ellipse::findIntersectWithLine(Point2DF closestPoint)
{
    m_vertices.clear();

    float m = (closestPoint.getY() - m_center.getY()) / (closestPoint.getX() - m_center.getX());
    float c = m_center.getY() - m * m_center.getX();
    float A = std::pow(m_b, 2) + std::pow(m * m_a, 2);
    float B = -2 * std::pow(m_b, 2) * m_center.getX() + 2 * std::pow(m_a, 2) * c * m - 2 * std::pow(m_a, 2) * m * m_center.getY();
    float C = std::pow(m_b * m_center.getX(),2) + std::pow(m_a * c, 2) - 2 * std::pow(m_a, 2) * c * m_center.getY() + std::pow(m_a * m_center.getY(), 2) - std::pow(m_a * m_b, 2);

    float delta = std::pow(B, 2) - 4 * A * C;

    float x1, x2;
    if(delta < 0)
    {
        return;
    }
    else if(delta == 0)
    {
        x1 = -1 * (B/2*A);
        x2 = x1;
    }
    else
    {
        x1 = (-B + sqrt(delta)) / (2 * A);
        x2 = (-B - sqrt(delta)) / (2 * A);
    }

    float y1 = m * x1 + c;
    float y2 = m * x2 + c;



    if(x1 < x2)
    {
        m_vertices.push_back(Point2DF(x2, y2));

    }
    else
    {
        m_vertices.push_back(Point2DF(x1, y1));
    }
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
