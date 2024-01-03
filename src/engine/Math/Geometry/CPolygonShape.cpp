#include "CPolygonShape.h"

CPolygonShape::CPolygonShape()
{

}

const Vector2D<float> &CPolygonShape::vertexAt(int index) const
{
    return m_vertices[index];
}

void CPolygonShape::setVertexAt(int index, Vector2D<float> vertex)
{
    m_vertices[index] = vertex;
}

std::vector<Vector2D<float>> CPolygonShape::vertices() const
{
    return m_vertices;
}

void CPolygonShape::pushVertex(float x, float y)
{
    m_vertices.emplace_back(x, y);
}

std::pair<float, float> CPolygonShape::projection(Vector2D<float> axis)
{
    float min = std::numeric_limits<float>::infinity();
    float max = -std::numeric_limits<float>::infinity();

    for (const Vector2D<float> &vertex: m_vertices)
    {
        Vector2D<float> actual_vertex(vertex.x + m_x, vertex.y + m_y);
        float dotProduct = axis.dotProduct(actual_vertex);
        min = std::min(min, dotProduct);
        max = std::max(max, dotProduct);
    }
    return std::make_pair(min, max);
}

void CPolygonShape::updatePosition(float X, float Y)
{
    m_x = X;
    m_y = Y;
}

Vector2D<float> CPolygonShape::center()
{
    Vector2D<float> G;
    for (const Vector2D<float> &vertex: m_vertices)
    {
        G.x += (vertex.x + m_x);
        G.y += (vertex.y + m_y);
    }

    G.x /= m_vertices.size();
    G.y /= m_vertices.size();

    return G;
}
