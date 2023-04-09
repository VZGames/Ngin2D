#ifndef ISHAPE_H
#define ISHAPE_H

#include <SDL2/SDL.h>
#include "Defines/Defines.h"
#include "Math/point2d.h"

class IShape
{  
protected:
    float m_x, m_y;
    std::vector<Point2DF> m_vertices;

public:
    virtual std::vector<Point2DF> vertices() const = 0;
    virtual Point2DF center() const = 0;
    virtual const SDL_FRect &getRect() const = 0;
    virtual SizeF size() const = 0;
    virtual Point2DF position() const = 0;
    virtual const char *type() const = 0;
    virtual bool contain(Point2DF point) = 0;
    virtual float acreage() = 0;
    virtual float perimeter() = 0;

};
#endif // ISHAPE_H
