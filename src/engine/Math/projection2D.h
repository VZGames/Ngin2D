#ifndef PROJECTION_H
#define PROJECTION_H


class Projection2D
{
public:
    Projection2D();
    Projection2D(float min, float max);

    bool overlap(const Projection2D &b);

    float gap(const Projection2D& b);


private:
    float m_min;
    float m_max;
};
#endif // PROJECTION_H
