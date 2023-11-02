#ifndef IECSYSTEM_H
#define IECSYSTEM_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(GameNgin)
class IECSystem
{
public:
    virtual void update(float dt) = 0;
};
END_NAMESPACE

#endif // IECSYSTEM_H
