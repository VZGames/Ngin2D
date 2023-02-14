#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
public:
    Point2D(int x, int y);

    Point2D();


    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);




private:
    int x,y;
};
#endif // POINT2D_H


inline Point2D::Point2D(int x, int y) : x(x),
    y(y)
{}

inline Point2D::Point2D(): x(0), y(0)
{}

inline int Point2D::getX() const
{
    return x;
}

inline void Point2D::setX(int newX)
{
    x = newX;
}

inline int Point2D::getY() const
{
    return y;
}

inline void Point2D::setY(int newY)
{
    y = newY;
}

