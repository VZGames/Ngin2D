#ifndef ASCENE_H
#define ASCENE_H

#include "CommonDefine.h"
#include "CEntity.h"

BEGIN_NAMESPACE(GameNgin)
class AScene
{
public:
    virtual void init() = 0;
    virtual void update(std::vector<GameNgin::CEntity*> &entities, float dt) = 0;
    virtual void render() = 0;
};
END_NAMESPACE

#endif // ASCENE_H
