#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct HealthComponent: public ComponentBase<HealthComponent>
{
    HealthComponent(float max): max(max){}
    float current, max;
};
}

#endif // HEALTHCOMPONENT_H
