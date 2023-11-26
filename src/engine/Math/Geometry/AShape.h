#ifndef ASHAPE_H
#define ASHAPE_H

#include "vector2D.h"
#include "LoggerDefines.h"
#include "CCamera.h"

class AShape
{
private:
    engine::CCamera *m_camera(void);
    bool  m_is_box{false};
    bool  m_collided{false};

protected:
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    std::vector<Vector2DF> m_axes;


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
    void pushAxis(Vector2DF axis) { m_axes.emplace_back(axis); }
    std::vector<Vector2DF> axes() const { return m_axes; }
    bool isBox() const { return m_is_box; }
    void setBox(bool isBox = true) { m_is_box = isBox; }
    void setCollided(bool collided)
    {
        if(collided == m_collided)
        {
            return;
        }
        m_collided = collided;
        DBG("IS COLLISION")
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
    virtual Vector2DF center() { return Vector2DF(); }
    virtual void updatePosition(float x, float y) { setX(x); setY(y); };
    virtual std::pair<float, float>  projection(Vector2DF axis) { (void)axis; return std::make_pair(0,0); }
    virtual float perimeter() { return 0.0f; };
    virtual float acreage() { return 0.0f; };
};
#endif // ASHAPE_H
