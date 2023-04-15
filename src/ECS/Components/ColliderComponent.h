#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include <SDL2/SDL.h>
#include "ComponentBase.h"
#include "Math/Shape/IShape.h"

namespace ngin2D {
struct ColliderComponent: public ComponentBase<ColliderComponent>, public IShape
{
    ColliderComponent(float w, float h): w(w), h(h){}
    float x, y;
    float w, h;

    void setRect(SDL_FRect rect)
    {
        m_rect = rect;
    }

    void setCenter(Point2DF center)
    {
        m_center = center;
    }

    // IShape interface
public:
    virtual SizeF size() const override
    {
        return SizeF {w, h};
    }

    virtual Point2DF position() const override
    {
        return Point2DF(x, y);
    }

    virtual const char *type() const override
    {
        return "ColliderBox";
    }
};
}
#endif // COLLIDERCOMPONENT_H
