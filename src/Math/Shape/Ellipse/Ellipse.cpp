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
    float m = std::abs((closestPoint.getY() - m_center.getY()) / (closestPoint.getX() - m_center.getX()));
    float c = 0;
    float expressionA = std::pow(m_b, 2) + std::pow(m * m_a, 2);
    float expressionB = 2 * m * c - 2 * m * m_center.getX() * std::pow(m_a, 2);
    float expressionC = std::pow(m_center.getX(), 2) * std::pow(m, 2) * std::pow(m_a, 2) + std::pow(m_center.getY(), 2) * std::pow(m_b, 2) - std::pow(m_b, 2) * std::pow(m_a, 2);

    float delta = std::pow(expressionB, 2) - 4 * expressionA * expressionC;

    float x1, x2;
    if(delta < 0)
    {
        return;
    }
    else if(delta == 0)
    {
        x1 = -1 * (expressionB/2*expressionA);
        x2 = x1;
    }
    else
    {
        x1 = (-expressionB + sqrt(delta)) / (2 * expressionA);
        x2 = (-expressionB - sqrt(delta)) / (2 * expressionA);
    }

    float y1 = m * x1 + c;
    float y2 = m * x2 + c;

    m_vertices.push_back(Point2DF(x1, y1));
    m_vertices.push_back(Point2DF(x2, y2));

    std::cout << Point2DF(x1, y1) << Point2DF(x2, y2);
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
