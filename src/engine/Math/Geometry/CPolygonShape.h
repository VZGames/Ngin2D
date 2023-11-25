#ifndef CPOLYGONSHAPE_H
#define CPOLYGONSHAPE_H

#include "AShape.h"
#include "vector2D.h"

class CPolygonShape: public AShape
{
private:
    std::vector<Vector2DF> m_vertices_origin;
    std::vector<Vector2DF> m_vertices;

public:
    CPolygonShape();

    Vector2DF &vertexAt(int index);
    void setVertexAt(int index, Vector2DF vertex);
    std::vector<Vector2DF> vertices() const;
    void pushVertex(float x, float y);

    // AShape interface
public:
    virtual std::pair<float, float> projection(Vector2DF axes) override;
    virtual void updatePosition(float X, float Y) override;
};

#endif // CPOLYGONSHAPE_H
