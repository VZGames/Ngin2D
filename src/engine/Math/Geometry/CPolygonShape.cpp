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

void CPolygonShape::pushVertex(float x, float y)
{
    float scale = engine::CCamera::instance()->scale();
    m_vertices_origin.emplace_back(Vector2DF(x, y));
    m_vertices.emplace_back(Vector2DF((x * scale) + m_x, (y * scale) + m_y));
}

std::pair<float, float> CPolygonShape::projection(Vector2DF axis)
{
    float min = std::numeric_limits<float>::infinity();
    float max = -std::numeric_limits<float>::infinity();

    for (const Vector2DF &vertex: m_vertices)
    {
        float dotProduct = axis.dotProduct(vertex);
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
        for (int i = 0; i < static_cast<int>(m_vertices.size()); i++)
        {
            m_vertices[i].x = (m_vertices_origin[i].x * scale) + m_x;
            m_vertices[i].y = (m_vertices_origin[i].y * scale) + m_y;
        }
    }
}
