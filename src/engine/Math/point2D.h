#ifndef POINT2D_H
#define POINT2D_H

#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "vector2D.h"

template<typename T>
class Point2D
{
public:
    Point2D(T x, T y): m_x(x),m_y(y){}

    Point2D(): m_x(0), m_y(0){}

    Point2D(const Point2D &copy)
    {
        this->m_x = copy.m_x;
        this->m_y = copy.m_y;
    }

    Point2D<T> &operator=(const Point2D<T> &other)
    {
        this->m_x = other.m_x;
        this->m_y = other.m_y;
        return *this;
    }

    bool operator==(Point2D<T> other)
    {
        return this->m_x == other.m_x && this->m_y == other.m_y;;
    }

    Point2D<T> &operator-=(const Point2D<T> &other)
    {
        this->m_x -= other.m_x;
        this->m_y -= other.m_y;
        return *this;
    }

    Point2D<T> &operator+=(const Point2D<T> &other)
    {
        this->m_x += other.m_x;
        this->m_y += other.m_y;
        return *this;
    }


    Point2D<T> &operator*=(const T scale)
    {
        this->m_x *= scale;
        this->m_y *= scale;
        return *this;
    }

    Point2D<T> &operator/=(const T scale)
    {
        this->m_x /= scale;
        this->m_y /= scale;
        return *this;
    }

    Point2D<T> operator+(const Point2D<T> &other)
    {
        Point2D<T> point = *this;
        point.m_x += other.m_x;
        point.m_y += other.m_y;
        return point;
    }

    Point2D<T> operator-(const Point2D<T> &other)
    {
        Point2D<T> point = *this;
        point.m_x -= other.m_x;
        point.m_y -= other.m_y;
        return point;
    }

    Point2D<T> &operator*(const T scale)
    {
        this->m_x *= scale;
        this->m_y *= scale;
        return *this;
    }



    Point2D<T> &updateX(const T &x)
    {
        this->m_x += x;
        return *this;
    }
    Point2D<T> &updateY(const T &y)
    {
        this->m_y += y;
        return *this;
    }

    const char *toString()
    {
        std::string &res = std::to_string(m_x) + ", " + std::to_string(m_y);
         return res.c_str();
    }

    double distance(const Point2D<T> &other)
    {
         return std::sqrt(std::pow(other.m_x - this->m_x, 2) + std::pow(other.m_y - this->m_y, 2));
    }

    T x() const
    {
         return m_x;
    }

    void setX(T newX)
    {
         m_x = newX;
    }

    T y() const
    {
        return m_y;
    }

    void setY(T newY)
    {
        m_y = newY;
    }

    Vector2D<T> toVector()
    {
        return Vector2D<T>(m_x, m_y);
    }

    Point2D<T> closestPoint(std::vector<Point2D<T>> points)
    {
        std::vector<float> dists;
        for(Point2D<T> &point: points)
        {
            float dist = this->distance(point);
            dists.push_back(dist);
        }

        int minDistAt = std::min_element(dists.begin(), dists.end()) - dists.begin();
        return points[minDistAt];
    }


    static Point2D<T> fromVector(const Vector2DF &vec)
    {
        return Point2D<T>(vec.x, vec.y);
    }

    // log
    friend std::ostream &operator<<(std::ostream &out, const Point2D<T> &val)
    {
        out << " (" << val.m_x << ", " << val.m_y << ") \n";
        return out;
    }

private:
    T m_x,m_y;
};

using Point2DI = Point2D<int>;
using Point2DF = Point2D<float>;
using Point2DLF = Point2D<double>;
using ListPoint2DI = std::vector<Point2DI>;
using ListPoint2DF = std::vector<Point2DF>;
using ListPoint2DLF = std::vector<Point2DLF>;

#endif // POINT2D_H



