#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Math/Shape/IShape.h"
#include "Math/math2D.h"

class Ellipse: public IShape
{
public:
    Ellipse(float a, float b);
    Ellipse(float a, float b, float x, float y);

    // IShape interface
public:
    virtual const SDL_FRect &getRect() const override;
    virtual SizeF size() const override;
    virtual bool contain(Point2DF M) override;
    virtual Point2DF getPosition() const override;
    virtual const char *getTypeName() const override;
    virtual float acreage() override;
    virtual float perimeter() override;

    Point2DF getCenterI() const;
    const float &radiusX() const;
    const float &radiusY() const;

private:
    Point2DF m_centerI;
    float m_width, m_height;
    float m_a, m_b;
    SDL_FRect m_rect;
};

#endif // ELLIPSE_H