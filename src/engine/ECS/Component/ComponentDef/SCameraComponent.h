#ifndef SCAMERACOMPONENT_H
#define SCAMERACOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"
#include "offset2D.h"

BEGIN_NAMESPACE(Ngin)
class CEntity;
struct SCameraComponent: public CComponent
{
    SCameraComponent()
    {
        m_name = __FUNCTION__;
    }

    Offset offset{0.0f, 0.0f};
};
END_NAMESPACE

#endif // SCAMERACOMPONENT_H
