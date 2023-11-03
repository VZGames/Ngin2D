#ifndef CGAMESCENE_H
#define CGAMESCENE_H

#include "CommonDefine.h"
#include "AScene.h"

BEGIN_NAMESPACE(GameScript)
class CGameScene: public GameNgin::AScene
{
public:
    CGameScene();

    virtual void init() override;
    virtual void render() override;
};
END_NAMESPACE

#endif // CGAMESCENE_H
