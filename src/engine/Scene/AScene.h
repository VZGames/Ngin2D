#ifndef ASCENE_H
#define ASCENE_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(GameNgin)
class AScene
{
public:
    virtual void init() = 0;
    virtual void update(float dt) = 0;
    virtual void render() = 0;
};
END_NAMESPACE

#endif // ASCENE_H
