#include "projection2D.h"
#include "Utils/Logger/Logger.h"

Projection2D::Projection2D(): m_min(0.0f), m_max(0.0f)
{}

Projection2D::Projection2D(float min, float max): m_min(min), m_max(max)
{
}

bool Projection2D::overlap(const Projection2D &b)
{
    return m_min <= b.m_max && m_max >= b.m_min;
}

float Projection2D::gap(const Projection2D &b)
{
    if (!this->overlap(b)) { return 0.f; }
    return std::min(this->m_max, b.m_max) - std::max(this->m_min, b.m_min);
}
