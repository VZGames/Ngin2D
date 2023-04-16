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

    m_center = Point2DF(m_x + gX, m_y + gY);

    float w,h;
    float xMin, xMax;
    float yMin, yMax;

    xMin = m_vertices[0].getX() <= m_x
            ?m_x - m_vertices[0].getX()
            :m_vertices[0].getX() - m_x;
    yMin = m_vertices[0].getY() <= m_y
            ?m_y - m_vertices[0].getY()
            :m_vertices[0].getY() - m_y;

    xMax = xMin;
    yMax = yMin;

    for (Point2DF vertex: m_vertices)
    {
        float realX = vertex.getX() - m_x;
        float realY = vertex.getY() - m_y;

        xMin = min(xMin, realX);
        xMax = max(xMax, realX);
        yMin = min(yMin, realY);
        yMax = max(yMax, realY);
    }

    w = xMax - xMin;
    h = yMax - yMin;

    m_size = {w, h};
    m_position = Point2DF(m_x, m_y);
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



