#ifndef POLYGON_H
#define POLYGON_H


#include "Math/Shape/IShape.h"
#include "Math/math2D.h"

class Polygon: public IShape
{
public:
    Polygon();

private:
    std::vector<float> m_points;
};

#endif // POLYGON_H
