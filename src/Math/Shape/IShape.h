#ifndef ISHAPE_H
#define ISHAPE_H

#include <SDL2/SDL.h>
#include "Defines/Defines.h"
#include "Math/math2D.h"
#include "Math/projection2D.h"
#include "Utils/Utils.h"

class IShape
{  
protected:
    float m_x, m_y;
    SDL_FRect m_rect;
    ListPoint2DF m_vertices;
    ListVector2DF m_axes;
    std::vector<Projection2D> m_projections;

public:
    inline ListVector2DF axes()
    {
        for (int i = 0; i < m_vertices.size(); i++) {
            Point2DF p1 = m_vertices[i];
            Point2DF p2 = m_vertices[i + 1 == m_vertices.size()? 0: i+1];

            Vector2DF edge = p1.toVector() - p2.toVector();

            Vector2DF normal = edge.perp();

            float magnitude = normal.magnitude();

            // convert normal vector to unit vector(length to 1)
            if(magnitude != 0)
            {
                normal *= 1/magnitude;
            }

            m_axes.push_back(normal);
        }
        return m_axes;
    }

    inline void project(Vector2DF axis)
    {
        float dotProductMin = axis.dotProduct(m_vertices[0].toVector());
        float dotProductMax = dotProductMin;

        for (int i = 0; i < m_vertices.size(); i++) {
            float dotProduct = axis.dotProduct(m_vertices[i].toVector());
            dotProductMin = min(dotProductMin, dotProduct);
            dotProductMax = max(dotProductMax, dotProduct);
        }
        // [Formula] project = (dotProduct/|axis|^2) * axis
        Vector2DF projectMin = axis * dotProductMin;
        Vector2DF projectMax = axis * dotProductMax;
        m_projections.push_back(Projection2D(projectMin, projectMax));

    }

    inline void setVertices(ListPoint2DF &vertices)
    {
        m_vertices = vertices;
    }

    inline std::vector<Point2DF> vertices() const
    {
        return m_vertices;
    }

    inline std::vector<Projection2D> projections() const
    {
        return m_projections;
    }


    inline const SDL_FRect &rect() const
    {
        return m_rect;
    };

    virtual Point2DF center() const = 0;
    virtual SizeF size() const = 0;
    virtual Point2DF position() const = 0;
    virtual const char *type() const = 0;
    virtual bool contain(Point2DF point) { return 0; };
    virtual float acreage() { return 0.0f; };
    virtual float perimeter() { return 0.0f; };

};
#endif // ISHAPE_H
