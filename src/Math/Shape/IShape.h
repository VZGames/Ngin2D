#ifndef ISHAPE_H
#define ISHAPE_H

#include <SDL2/SDL.h>
#include "Defines/Defines.h"
#include "Math/math2D.h"

class IShape
{  
protected:
    float m_x, m_y;
    ListPoint2DF m_vertices;
    ListVector2DF m_axes;

public:
    inline ListVector2DF axes()
    {
        for (int i = 0; i < m_vertices.size(); i++) {
            Point2DF p1 = m_vertices[i];
            Point2DF p2 = m_vertices[i + 1 == m_vertices.size()? 0: i+1];

            float a = p2.getX() - p1.getX();
            float b = p2.getY() - p1.getY();

            Vector2DF u(a,b);
            Vector2DF normal = u.perp();

            float magnitude = normal.magnitude();
            if(magnitude != 0)
            {
                normal *= 1/magnitude;
            }

            m_axes.push_back(normal);
        }
        return m_axes;
    }

    inline void setVertices(ListPoint2DF &vertices)
    {
        m_vertices = vertices;
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
