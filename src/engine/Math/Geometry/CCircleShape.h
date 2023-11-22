#ifndef CCIRCLESHAPE_H
#define CCIRCLESHAPE_H

#include "AShape.h"
#define PI 3.141592654

class CCircleShape: public AShape
{
private:
    float m_diameter;

public:
    CCircleShape();
};

#endif // CCIRCLESHAPE_H
