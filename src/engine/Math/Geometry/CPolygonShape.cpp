#include "CPolygonShape.h"

CPolygonShape::CPolygonShape()
{

}

Vector2DF &CPolygonShape::vertexAt(int index)
{
    return m_vertices[index];
}

void CPolygonShape::setVertexAt(int index, Vector2DF vertex)
{
    m_vertices[index] = vertex;
}

std::vector<Vector2DF> CPolygonShape::vertices() const
{
    return m_vertices;
}

void CPolygonShape::setVertices(std::vector<Vector2DF> &vertices)
{
    std::copy(vertices.begin(), vertices.end(), std::back_inserter(m_vertices));
}

void CPolygonShape::pushVertex(Vector2DF vertex)
{
    m_vertices.emplace_back(vertex);
}

std::pair<float, float> CPolygonShape::projection(Vector2DF axis)
{
    float min = std::numeric_limits<float>::infinity();
    float max = -std::numeric_limits<float>::infinity();

    for (Vector2DF &vertex: m_vertices)
    {
        float dotProduct = axis.dotProduct(Vector2D<float>(m_x, m_y) + vertex);
        min = std::min(min, dotProduct);
        max = std::max(max, dotProduct);
    }
    return std::make_pair(min, max);
}
