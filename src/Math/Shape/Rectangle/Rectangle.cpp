#include "Rectangle.h"

Rectangle::Rectangle(float width, float height) : m_width(width),
    m_height(height)
{
    m_type = TYPE_SHAPE::RECTANGLE;
    m_rect = {m_x, m_y, m_width, m_height};
    m_x = 0.0f;
    m_y = 0.0f;
    m_center = Point2DF(m_x + m_width/2, m_y + m_height/2);
    m_size = SizeF {m_width, m_height};
    m_position = Point2DF(m_x, m_y);
}

Rectangle::Rectangle(float width, float height, float x, float y) : m_width(width),
    m_height(height)
{
    m_type = TYPE_SHAPE::RECTANGLE;
    m_x = x;
    m_y = y;
    m_rect = {m_x, m_y, m_width, m_height};
    m_center = Point2DF(m_x + m_width/2, m_y + m_height/2);
    m_size = SizeF {m_width, m_height};
    m_position = Point2DF(m_x, m_y);
}

bool Rectangle::contain(Point2DF point)
{
    return 0;
}

float Rectangle::acreage()
{
    return m_height * m_width;
}

float Rectangle::perimeter()
{
    return (m_height + m_width) * 2;
}
