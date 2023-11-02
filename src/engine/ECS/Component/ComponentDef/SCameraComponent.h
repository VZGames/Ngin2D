#ifndef SCAMERACOMPONENT_H
#define SCAMERACOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"

BEGIN_NAMESPACE(GameNgin)
struct SCameraComponent: public CComponent
{
    SCameraComponent()
    {
        m_name = __FUNCTION__;
    }
};
END_NAMESPACE

#endif // SCAMERACOMPONENT_H
