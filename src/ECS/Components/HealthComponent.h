#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct HealthComponent: public ComponentBase<HealthComponent>
{
    HealthComponent(int max): max(max){}
    int max;
};
}

#endif // HEALTHCOMPONENT_H
