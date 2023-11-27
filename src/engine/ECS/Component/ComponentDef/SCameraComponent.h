#ifndef SCAMERACOMPONENT_H
#define SCAMERACOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"
#include "CCameraSys.h"
#include "offset2D.h"

BEGIN_NAMESPACE(engine)
class CEntity;
struct SCameraComponent: public CComponent
{
    SCameraComponent(CEntity *target): CComponent(__FUNCTION__)
    {
        CCameraSys::instance()->setTarget(target);
    }

    Offset offset{0.0f, 0.0f};
};
END_NAMESPACE

#endif // SCAMERACOMPONENT_H
