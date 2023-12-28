#ifndef CPOLYGONSHAPE_H
#define CPOLYGONSHAPE_H

#include "AShape.h"
#include "vector2D.h"

class CPolygonShape: public AShape
{
private:
    std::vector<Vector2D<float>> m_vertices_origin;
    std::vector<Vector2D<float>> m_vertices;

public:
    CPolygonShape();

    Vector2D<float> &vertexAt(int index);
    void setVertexAt(int index, Vector2D<float> vertex);
    std::vector<Vector2D<float>> vertices() const;
    void pushVertex(float x, float y);

    // AShape interface
public:
    virtual std::pair<float, float> projection(Vector2D<float> axes) override;
    virtual void updatePosition(float X, float Y) override;
    virtual Vector2D<float> center() override;
};

#endif // CPOLYGONSHAPE_H
