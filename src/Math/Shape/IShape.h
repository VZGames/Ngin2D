#ifndef ISHAPE_H
#define ISHAPE_H

#include <SDL2/SDL.h>
#include "Defines/Defines.h"
#include "Math/point2d.h"

class IShape
{  
public:
    virtual const SDL_FRect &getRect() const = 0;
    virtual Size size() const = 0;
    virtual Point2DF getPosition() const = 0;
    virtual const char *getTypeName() const = 0;
    virtual bool contain(Point2DF point) = 0;
    virtual float acreage() = 0;
    virtual float perimeter() = 0;

};
#endif // ISHAPE_H
