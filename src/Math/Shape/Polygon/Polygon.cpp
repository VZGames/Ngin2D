#include "Polygon.h"
#include "Utils/Utils.h"

Polygon::Polygon(float x, float y, ListPoint2DF &vertices)
{
    m_vertices = vertices;

    float w,h;
    float xMin, xMax;
    float yMin, yMax;

    xMin = m_vertices[0].getX() <= x
            ?x - m_vertices[0].getX()
            :m_vertices[0].getX() - x;
    yMin = m_vertices[0].getY() <= y
            ?y - m_vertices[0].getY()
            :m_vertices[0].getY() - y;

    xMax = xMin;
    yMax = yMin;

    for (Point2DF vertex: m_vertices)
    {
        float realX = vertex.getX() - x;
        float realY = vertex.getY() - y;

        xMin = min(xMin, realX);
        xMax = max(xMax, realX);
        yMin = min(yMin, realY);
        yMax = max(yMax, realY);
    }

    w = xMax - xMin;
    h = yMax - yMin;

    m_size = {w, h};
    m_x = xMin;
    m_y = yMin;
    m_position = Point2DF(m_x + x, m_y + y);


    int k = m_vertices.size();
    for (int i = 0; i < m_vertices.size(); i++) {
        m_center += m_vertices[i];
    }
    m_center /= k;
}

TYPE_SHAPE Polygon::type() const
{
    return TYPE_SHAPE::POLYGON;
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



