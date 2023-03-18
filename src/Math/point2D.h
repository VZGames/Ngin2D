#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
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

    void operator=(Point2D<T> &right)
    {
        this->x = right.x;
        this->y = right.y;
    }

    T &operator-=(Point2D<T> &right)
    {
        this->x -= right.x;
        this->y -= right.y;
        return this;
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

    // log
    friend std::ostream &operator<<(std::ostream &out, Point2D<T> &val)
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

#endif // POINT2D_H



