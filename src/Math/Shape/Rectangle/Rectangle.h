#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ECS/Components/Components.h"
#include "Math/Shape/IShape.h"
#include "Math/math2D.h"

class Rectangle : public IShape
{
public:
    Rectangle(float width, float height);
    Rectangle(float width, float height, float x, float y);

    // IShape interface
public:
    virtual SizeF size() const override;
    virtual Point2DF getPosition() const override;
    virtual Point2DF getCenterI() const override;
    virtual const char *getTypeName() const override;
    virtual bool contain(Point2DF point) override;
    virtual float acreage() override;
    virtual float perimeter() override;
    virtual const SDL_FRect &getRect() const override;

private:
    Point2DF m_centerI;
    float m_width, m_height;
    SDL_FRect m_rect;
};

#endif // RECTANGLE_H
