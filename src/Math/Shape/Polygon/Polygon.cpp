#include "Polygon.h"

Polygon::Polygon(float x, float y, const std::vector<Point2DF> &points) : m_x(x),
    m_y(y),
    m_points(points)
{}

const SDL_FRect &Polygon::getRect() const
{
    return m_rect;
}

SizeF Polygon::size() const
{
    return SizeF {0, 0};
}

Point2DF Polygon::getPosition() const
{
    return Point2DF(m_x, m_y);
}

const char *Polygon::getTypeName() const
{
    return "polygon";
}

bool Polygon::contain(Point2DF point)
{
    return 0;
}

float Polygon::acreage()
{
    return 0.0;
}

float Polygon::perimeter()
{
    return 0.0;
}

const std::vector<Point2DF> &Polygon::points() const
{
    return m_points;
}

