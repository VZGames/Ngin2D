#ifndef POINT2D_H
#define POINT2D_H

#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "vector2D.h"
#include "Utils/Logger/Logger.h"

template<typename T>
class Point2D
{
public:
    Point2D(T x, T y): x(x),y(y){}

    Point2D(): x(0), y(0){}

    Point2D(const Point2D &copy)
    {
        this->x = copy.x;
        this->y = copy.y;
    }

    Point2D<T> &operator=(const Point2D<T> &other)
    {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

    bool operator==(Point2D<T> other)
    {
        return this->x == other.x && this->y == other.y;;
    }

    Point2D<T> &operator-=(const Point2D<T> &other)
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    Point2D<T> &operator+=(const Point2D<T> &other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Point2D<T> &operator/=(const T scale)
    {
        this->x /= scale;
        this->y /= scale;
        return *this;
    }

    Point2D<T> operator+(const Point2D<T> &other)
    {
        Point2D<T> point = *this;
        point.x += other.x;
        point.y += other.y;
        return point;
    }

    Point2D<T> operator-(const Point2D<T> &other)
    {
        Point2D<T> point = *this;
        point.x -= other.x;
        point.y -= other.y;
        return point;
    }

    Point2D<T> &operator*(const T scale)
    {
        this->x *= scale;
        this->y *= scale;
        return *this;
    }



    Point2D<T> &updateX(const T &x)
    {
        this->x += x;
        return *this;
    }
    Point2D<T> &updateY(const T &y)
    {
        this->y += y;
        return *this;
    }

    const char *toString()
    {
         std::string &res = std::to_string(x) + ", " + std::to_string(y);
         return res.c_str();
    }

    double distance(const Point2D<T> &other)
    {
        return std::sqrt(std::pow(other.x - this->x, 2) + std::pow(other.y - this->y, 2));
    }

    T getX() const
    {
        return x;
    }

    void setX(T newX)
    {
        x = newX;
    }

    T getY() const
    {
        return y;
    }

    void setY(T newY)
    {
        y = newY;
    }

    Vector2D<T> toVector()
    {
        return Vector2D<T>(x, y);
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
        out << " (" << val.x << ", " << val.y << ") \n";
        return out;
    }

private:
    T x,y;
};

using Point2DI = Point2D<int>;
using Point2DF = Point2D<float>;
using Point2DLF = Point2D<double>;
using ListPoint2DI = std::vector<Point2DI>;
using ListPoint2DF = std::vector<Point2DF>;
using ListPoint2DLF = std::vector<Point2DLF>;

#endif // POINT2D_H



