#include "projection2D.h"

Projection2D::Projection2D(): m_min(0.0f), m_max(0.0f)
{}

Projection2D::Projection2D(float min, float max): m_min(min), m_max(max)
{}

bool Projection2D::overlap(const Projection2D &projectB)
{
    return !(m_max < projectB.m_min || projectB.m_max < m_min);
}
