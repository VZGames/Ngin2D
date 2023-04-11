#ifndef POLYGON_H
#define POLYGON_H

#include "Math/Shape/IShape.h"
#include "Math/math2D.h"

class Polygon: public IShape
{
public:
    Polygon(float x, float y);


    // IShape interface
public:
    virtual const SDL_FRect &rect() const override;
    virtual SizeF size() const override;
    virtual Point2DF position() const override;
    virtual Point2DF center() const override;
    virtual const char *type() const override;
    virtual bool contain(Point2DF point) override;
    virtual float acreage() override;
    virtual float perimeter() override;
    virtual std::vector<Point2DF> vertices() const override;

private:
    Point2DF m_centerI;
    SDL_FRect m_rect;

};

#endif // POLYGON_H
