#ifndef SCAMERACOMPONENT_H
#define SCAMERACOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"
#include "CCameraSys.h"
#include "offset2D.h"
#include "vector2D.h"

BEGIN_NAMESPACE(engine)
class CEntity;
struct SCameraComponent: public CComponent
{
    SCameraComponent(Vector2D<float> target): CComponent(__FUNCTION__)
    {
        CCameraSys::instance()->setTarget(std::move(target));
    }

    Offset offset{0.0f, 0.0f};
};
END_NAMESPACE

#endif // SCAMERACOMPONENT_H
