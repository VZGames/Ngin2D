#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
public:
    Point2D(int x, int y): x(x),y(y){}

    Point2D(): x(0), y(0){}


    int getX() const
    {
        return x;
    }

    void setX(int newX)
    {
        x = newX;
    }

    int getY() const
    {
        return y;
    }

    void setY(int newY)
    {
        y = newY;
    }

private:
    int x,y;
};


#endif // POINT2D_H



