#ifndef POLYGON_H
#define POLYGON_H

#include "Math/Shape/IShape.h"
#include "Math/math2D.h"

class Polygon: public IShape
{
public:
    Polygon(float x, float y, ListPoint2DF &vertices);


    // IShape interface
public:
    virtual TYPE_SHAPE type() const override;
    virtual bool contain(Point2DF point) override;
    virtual float acreage() override;
    virtual float perimeter() override;


private:
    SDL_FRect m_rect;

};

#endif // POLYGON_H
