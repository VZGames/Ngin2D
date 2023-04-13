#include "Polygon.h"
#include "Utils/Utils.h"

Polygon::Polygon(float x, float y, ListPoint2DF &vertices)
{
    m_x = x;
    m_y = y;
    m_vertices = vertices;

    int k = m_vertices.size();
    float gX, gY;
    for (int i = 0; i < m_vertices.size(); i++) {
        gX += m_vertices[i].getX();
        gY += m_vertices[i].getY();
    }
    gX /= k;
    gY /= k;

    m_centerI = Point2DF(m_x + gX, m_y + gY);
}

const SDL_FRect &Polygon::rect() const
{
    return m_rect;
}

SizeF Polygon::size() const
{
    float w,h;
    float xMin, xMax;
    float yMin, yMax;

    xMin = std::abs(m_vertices[0].getX()) < m_x
            ?m_x - std::abs(m_vertices[0].getX())
            :std::abs(m_vertices[0].getX()) - m_x;
    yMin = std::abs(m_vertices[0].getY()) < m_y
            ?m_y - std::abs(m_vertices[0].getY())
            :std::abs(m_vertices[0].getY()) - m_y;

    xMax = xMin;
    yMax = yMin;

    for (Point2DF vertex: m_vertices)
    {
        float _x = std::abs(vertex.getX()) < m_x
                ?m_x - std::abs(vertex.getX())
                :std::abs(vertex.getX()) - m_x;
        float _y = std::abs(vertex.getY()) < m_y
                ?m_y - std::abs(vertex.getY())
                :std::abs(vertex.getY()) - m_y;
        if(_x > xMin)
        {
            xMax = _x;
            xMin = xMax;
        }

        if(_y > yMin)
        {
            yMax = _y;
            yMin = yMax;
        }
    }

    w = xMax;
    h = yMax;

    std::cout << w << "," << h << std::endl;
    return SizeF {w, h};
}

Point2DF Polygon::position() const
{
    return Point2DF(m_x, m_y);
}

Point2DF Polygon::center() const
{
    return m_centerI;
}

const char *Polygon::type() const
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

std::vector<Point2DF> Polygon::vertices() const
{
    return m_vertices;
}


