#ifndef PROJECTION_H
#define PROJECTION_H

#include "vector2D.h"

class Projection2D
{
public:
    Projection2D();
    Projection2D(Vector2DF min, Vector2DF max);

    bool overlap(const Projection2D &projectB);

private:
    Vector2DF m_min, m_max;
};
#endif // PROJECTION_H
