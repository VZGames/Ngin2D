#ifndef SCAMERACOMPONENT_H
#define SCAMERACOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"
#include "Camera/CCameraSys.h"
#include "vector2D.h"

BEGIN_NAMESPACE(engine)
class CEntity;
struct SCameraComponent: public CComponent
{
    SCameraComponent(Vector2D<float> target): CComponent(__FUNCTION__)
    {
        CCameraSys::instance()->setTarget(std::move(target));
    }
};
END_NAMESPACE

#endif // SCAMERACOMPONENT_H
