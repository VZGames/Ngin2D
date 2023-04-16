#ifndef PROJECTION_H
#define PROJECTION_H

#include "vector2D.h"

class Projection2D
{
public:
    Projection2D();
    Projection2D(float min, float max);

    bool overlap(const Projection2D &projectB);

private:
    float m_min;
    float m_max;
};
#endif // PROJECTION_H
