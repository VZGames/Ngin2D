#include "projection2D.h"

Projection2D::Projection2D(): m_min(Vector2DF()), m_max(Vector2DF())
{}

Projection2D::Projection2D(Vector2DF min, Vector2DF max): m_min(min), m_max(max)
{}

bool Projection2D::overlap(const Projection2D &projectB)
{
    return !(m_max.x < projectB.m_min.x || projectB.m_max.x < m_min.x);
}
