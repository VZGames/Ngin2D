#ifndef ASHAPE_H
#define ASHAPE_H

#include "vector2D.h"
#include <LoggerDefines.h>

class AShape
{
private:
    bool  m_is_box{false};
    bool  m_collided{false};

protected:
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    std::vector<Vector2D<float>> m_axes;


public:
    float x() const { return m_x; }
    float y() const { return m_y; }
    float width() const { return m_width; }
    float height() const { return m_height; }
    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }
    void setWidth(float width) { m_width = width; }
    void setHeight(float height) { m_height = height; }
    void clearAxis() { m_axes.clear(); }
    void pushAxis(Vector2D<float> axis) { m_axes.emplace_back(axis); }
    std::vector<Vector2D<float>> axes() const { return m_axes; }
    bool isBox() const { return m_is_box; }
    void setBox(bool isBox = true) { m_is_box = isBox; }
    void setCollided(bool collided)
    {
        if(collided == m_collided)
        {
            return;
        }
        m_collided = collided;
//        DBG("IS COLLISION")
    }
    bool collided()
    {
        if(isBox()) { return m_collided; }
        else {
            DBG("This Shape is not Box")
            return false;
        }
    }

public:
    static bool checkCollision(AShape*, AShape*, Vector2D<float>&);

    static bool overlap(float A0, float A1, float B0, float B1)
    {
        return A0 <= B1 && A1 >= B0;
    }

    static float gap(float A0, float A1, float B0, float B1)
    {
        if (!overlap(A0, A1, B0, B1)) { return 0.0f; }
        return std::min(A1, B1) - std::max(A0, B0);
    }

public:
    virtual Vector2D<float> center() { return Vector2D<float>(); }
    virtual void updatePosition(float x, float y) { setX(x); setY(y); };
    virtual std::pair<float, float>  projection(Vector2D<float> axis) { (void)axis; return std::make_pair(0,0); }
    virtual float perimeter() { return 0.0f; };
    virtual float acreage() { return 0.0f; };
};
#endif // ASHAPE_H
