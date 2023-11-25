#include "CPolygonShape.h"

CPolygonShape::CPolygonShape()
{

}

Vector2DF &CPolygonShape::vertexAt(int index)
{
    return m_vertices_origin[index];
}

void CPolygonShape::setVertexAt(int index, Vector2DF vertex)
{
    m_vertices_origin[index] = vertex;
}

std::vector<Vector2DF> CPolygonShape::vertices() const
{
    if(m_vertices.size() > 0) return m_vertices;
    return m_vertices_origin;
}

void CPolygonShape::setVertices(std::vector<Vector2DF> &vertices)
{
    std::copy(vertices.begin(), vertices.end(), std::back_inserter(m_vertices_origin));
}

void CPolygonShape::pushVertex(Vector2DF vertex)
{
    m_vertices_origin.emplace_back(vertex);
}

std::pair<float, float> CPolygonShape::projection(Vector2DF axis)
{
    float min = std::numeric_limits<float>::infinity();
    float max = -std::numeric_limits<float>::infinity();

    for (const Vector2DF &vertex: m_vertices)
    {
        float dotProduct = axis.dotProduct(Vector2D<float>(m_x, m_y) + vertex);
        min = std::min(min, dotProduct);
        max = std::max(max, dotProduct);
    }
    return std::make_pair(min, max);
}

void CPolygonShape::updatePosition(float X, float Y)
{
    m_x = X;
    m_y = Y;
    {
        float scale = engine::CCamera::instance()->scale();
        m_vertices.clear();
        std::copy(m_vertices_origin.begin(), m_vertices_origin.end(), std::back_inserter(m_vertices));
        for (int i = 0; i < static_cast<int>(m_vertices.size()); i++)
        {
            m_vertices[i].x = (m_vertices_origin[i].x * scale) + m_x;
            m_vertices[i].y = (m_vertices_origin[i].y * scale) + m_y;
        }
    }
}
