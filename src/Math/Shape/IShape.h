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
    std::vector<Vector2F> m_axes;

public:
    inline std::vector<Vector2F> axes()
    {
        for (int i = 0; i < m_vertices.size(); i++) {
            Point2DF p1 = m_vertices[i];
            Point2DF p2 = m_vertices[i + 1 == m_vertices.size()? 0: i+1];

            float a = p2.getX() - p1.getX();
            float b = p2.getY() - p1.getY();

            Vector2F vecU(a,b);
            Vector2F vecNormal = vecU.perp();
            m_axes.push_back(vecNormal);
        }
        return m_axes;
    }

    virtual std::vector<Point2DF> vertices() const = 0;
    virtual Point2DF center() const = 0;
    virtual const SDL_FRect &rect() const = 0;
    virtual SizeF size() const = 0;
    virtual Point2DF position() const = 0;
    virtual const char *type() const = 0;
    virtual bool contain(Point2DF point) = 0;
    virtual float acreage() = 0;
    virtual float perimeter() = 0;

};
#endif // ISHAPE_H
