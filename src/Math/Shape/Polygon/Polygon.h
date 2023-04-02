#ifndef POLYGON_H
#define POLYGON_H

#include "Math/Shape/IShape.h"
#include "Math/math2D.h"

class Polygon: public IShape
{
public:
    Polygon(float x, float y, const std::vector<Point2DF> &points);


    // IShape interface
public:
    virtual const SDL_FRect &getRect() const override;
    virtual SizeF size() const override;
    virtual Point2DF getPosition() const override;
    virtual const char *getTypeName() const override;
    virtual bool contain(Point2DF point) override;
    virtual float acreage() override;
    virtual float perimeter() override;

    const std::vector<Point2DF> &points() const;

private:
    float m_x, m_y;
    SDL_FRect m_rect;
    std::vector<Point2DF> m_points;

};

#endif // POLYGON_H