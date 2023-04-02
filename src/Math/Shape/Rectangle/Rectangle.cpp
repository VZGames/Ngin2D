#include "Rectangle.h"

Rectangle::Rectangle(float width, float height) : m_width(width),
    m_height(height), m_x(0.0f), m_y(0.0f)
{
    m_rect = {m_x, m_y, m_width, m_height};
}

Rectangle::Rectangle(float width, float height, float x, float y) : m_width(width),
    m_height(height), m_x(x), m_y(y)
{
    m_rect = {m_x, m_y, m_width, m_height};
}


SizeF Rectangle::size() const
{
    return SizeF {m_width, m_height};
}

Point2DF Rectangle::getPosition() const
{
    return Point2DF(m_x, m_y);
}

const char *Rectangle::getTypeName() const
{
    return "rectangle";
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

const SDL_FRect &Rectangle::getRect() const
{
    return m_rect;
}

