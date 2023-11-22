#ifndef CPOLYGONSHAPE_H
#define CPOLYGONSHAPE_H

#include "AShape.h"
#include "vector2D.h"

class CPolygonShape: public AShape
{
private:
    std::vector<Vector2DF> m_vertices;

public:
    CPolygonShape();
};

#endif // CPOLYGONSHAPE_H
