#ifndef SHEALTHCOMPONENT_H
#define SHEALTHCOMPONENT_H

#include <CommonDefine.h>
#include "Component/CComponent.h"

BEGIN_NAMESPACE(engine)
struct SHealthComponent: public CComponent
{
    SHealthComponent(float max): CComponent(__FUNCTION__), max(max)
    {
    }
    float current, max;
};
END_NAMESPACE

#endif // SHEALTHCOMPONENT_H
