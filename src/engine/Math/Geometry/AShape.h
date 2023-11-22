#ifndef ASHAPE_H
#define ASHAPE_H

#include "vector2D.h"

class AShape
{
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
    void setY(float y) { m_x = y; }
    void setWidth(float width) { m_width = width; }
    void setHeight(float height) { m_height = height; }
    std::vector<Vector2DF> axes() const { return m_axes; }


public:
    virtual float perimeter() { return 0.0f; };
    virtual float acreage() { return 0.0f; };
};
#endif // ASHAPE_H
