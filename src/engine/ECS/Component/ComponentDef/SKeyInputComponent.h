#ifndef SKEYINPUTCOMPONENT_H
#define SKEYINPUTCOMPONENT_H

#include "CommonDefine.h"
#include "CComponent.h"

BEGIN_NAMESPACE(engine)
struct SKeyInputComponent: public CComponent
{
    SKeyInputComponent(): CComponent(__FUNCTION__) {}
};
END_NAMESPACE

#endif // SKEYINPUTCOMPONENT_H
