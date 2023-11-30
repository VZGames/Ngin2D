#ifndef CGAMESCENE_H
#define CGAMESCENE_H

#include "CommonDefine.h"
#include "AScene.h"
#include "CEntity.h"
#include "GameObjects/Cows/CCow.h"
#include "GameObjects/Player/CPlayer.h"

BEGIN_NAMESPACE(script)
class CGameScene: public engine::AScene
{
private:
    CPlayer player;
    CCow    cow;
    CCow    cow2;
    CCow    cow3;

public:
    CGameScene();

    // AScene interface
public:
    virtual void init() override;
    virtual void update(float) override;
    virtual void render() override;
};
END_NAMESPACE

#endif // CGAMESCENE_H
