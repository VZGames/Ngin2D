#include "CollisionManager.h"

CollisionManager::CollisionManager()
{

}

bool CollisionManager::IntersectCircles(Circle *A, Circle *B)
{
    return 0;
}

bool CollisionManager::IntersectCurvePolygon(Ellipse *A, Polygon *B)
{
    m_minGap = std::numeric_limits<float>::infinity();

    Point2DF closestPoint = A->center().closestPoint(B->vertices());


    A->findIntersectWithLine(closestPoint);
    A->appendVertices(A->center());

    for (auto &axis: A->axes())
    {
        Projection2D projectA = A->projectVertices(axis);
        Projection2D projectB = B->projectVertices(axis);

        float gap = projectA.gap(projectB);
        if (gap == 0.0f) // shapes are not overlapping
        {
            m_mtv = Vector2DF();
            return 0;
        }
        else
        {
            if (gap < m_minGap)
            {
                m_minGap = gap;
                m_mtv = axis * m_minGap;
            }
        }
    }


    LOG_INFO("COLLIDED");
    // need to reverse MTV if center offset and overlap are not pointing in the same direction
    bool notPointingInTheSameDirection = Vector2DF::dotProduct((A->center() - B->center()).toVector(), m_mtv) < 0;
    if (notPointingInTheSameDirection) { m_mtv = m_mtv * -1; }
    return 1;
}

bool CollisionManager::IntersectPolygons(Polygon* A, Polygon* B)
{
    m_minGap = std::numeric_limits<float>::infinity();

    for (auto &axis: A->axes())
    {
        Projection2D projectA = A->projectVertices(axis);
        Projection2D projectB = B->projectVertices(axis);

        float gap = projectA.gap(projectB);
        if (gap == 0.0f) // shapes are not overlapping
        {
            m_mtv = Vector2DF();
            return 0;
        }
        else
        {
            if (gap < m_minGap)
            {
                m_minGap = gap;
                m_mtv = axis * m_minGap;
            }
        }
    }

    for (auto &axis: B->axes())
    {
        Projection2D projectA = A->projectVertices(axis);
        Projection2D projectB = B->projectVertices(axis);

        float gap = projectA.gap(projectB);
        if (gap == 0.0f) // shapes are not overlapping
        {
            m_mtv = Vector2DF();
            return 0;
        }
        else
        {
            if (gap < m_minGap)
            {
                m_minGap = gap;
                m_mtv = axis * m_minGap;
            }
        }
    }

    // need to reverse MTV if center offset and overlap are not pointing in the same direction
    bool notPointingInTheSameDirection = Vector2DF::dotProduct((A->center() - B->center()).toVector(), m_mtv) < 0;
    if (notPointingInTheSameDirection) { m_mtv = m_mtv * -1; }
    return 1;
}

const Vector2DF &CollisionManager::mtv() const
{
    return m_mtv;
}
