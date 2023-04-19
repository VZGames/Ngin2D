#ifndef ISHAPE_H
#define ISHAPE_H

#include <SDL2/SDL.h>
#include <limits>
#include "Defines/Defines.h"
#include "Math/math2D.h"
#include "Math/projection2D.h"
#include "Utils/Utils.h"

class IShape
{  
protected:
    float m_x, m_y;
    SizeF m_size;
    Point2DF m_center;
    Point2DF m_position;
    SDL_FRect m_rect;
    TYPE_SHAPE m_type;
    ListPoint2DF m_vertices;
    ListVector2DF m_axes;

public:
    inline ListVector2DF axes()
    {
        if(m_type == TYPE_SHAPE::ELLIPSE)
        {
            m_axes.push_back((m_center - m_vertices[0]).toVector());
            return m_axes;
        }

        for (int i = 0; i < m_vertices.size(); i++)
        {
            Point2DF p1 = m_vertices[i];
            Point2DF p2 = m_vertices[i + 1 == m_vertices.size()? 0: i+1];

            Vector2DF edge = p1.toVector() - p2.toVector();

            Vector2DF normal = edge.perp();

            // convert normal vector to unit vector(length to 1)
            normal.toUnit();

            m_axes.push_back(normal);
        }

        return m_axes;
    }

    inline Projection2D project(Vector2DF axis)
    {

        float dotProductMin = std::numeric_limits<float>::infinity();
        float dotProductMax = -std::numeric_limits<float>::infinity();
        for (int i = 0; i < m_vertices.size(); i++)
        {
            float dotProduct = axis.dotProduct(m_vertices[i].toVector());
            dotProductMin    = min(dotProductMin, dotProduct);
            dotProductMax    = max(dotProductMax, dotProduct);
        }
        //        [Formula] project = (dotProduct/|axis|^2) * axis
        //        Vector2DF projectMin = axis * dotProductMin;
        //        Vector2DF projectMax = axis * dotProductMax;

        return Projection2D(dotProductMin, dotProductMax);

    }

    inline void setVertices(ListPoint2DF &vertices)
    {
        m_vertices = vertices;
    }

    inline void appendVertices(const Point2DF &point)
    {
        m_vertices.push_back(point);
    }

    inline void clearVertices()
    {
        m_vertices.clear();
    }

    inline std::vector<Point2DF> vertices() const
    {
        return m_vertices;
    }

    inline SDL_FRect rect() const
    {
        return m_rect;
    };

    inline Point2DF center() const
    {
        return m_center;
    };

    inline SizeF size() const
    {
        return m_size;
    }

    inline Point2DF position() const
    {
        return m_position;
    }

    inline TYPE_SHAPE type() const
    {
        return m_type;
    };

    virtual SizeF size()
    {
        return m_size;
    }

    virtual Point2DF position()
    {
        return m_position;
    }

    virtual bool contain(Point2DF point) { return 0; };
    virtual float acreage() { return 0.0f; };
    virtual float perimeter() { return 0.0f; };

};
#endif // ISHAPE_H
