#include "Rectangle.h"
#include <SDL2/SDL.h>

Rectangle::Rectangle(double width, double height) : m_width(width),
    m_height(height)
{}

Rectangle::Rectangle(double width, double height, int x, int y) : m_width(width),
    m_height(height), m_x(x), m_y(y)
{}


Size Rectangle::size() const
{
    return Size{(int)m_width, (int)m_height};
}

Point2DI Rectangle::getPosition() const
{
    return Point2DI(m_x, m_y);
}

const char *Rectangle::getTypeName() const
{
    return "rectangle";
}

bool Rectangle::contain(Point2DI point)
{
    SDL_Point _point = {point.getX(), point.getY()};
    SDL_Rect rect = {m_x,  m_y, (int)m_width, (int)m_height};
    return SDL_PointInRect(&_point, &rect);;
}

double Rectangle::acreage()
{
    return m_height * m_width;
}

double Rectangle::perimeter()
{
    return (m_height + m_width) * 2;
}

