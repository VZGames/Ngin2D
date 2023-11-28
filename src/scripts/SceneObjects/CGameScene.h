#ifndef CGAMESCENE_H
#define CGAMESCENE_H

#include "CommonDefine.h"
#include "Alias.h"
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
    std::vector<engine::CEntity*> m_entities;

public:
    CGameScene();

    // AScene interface
public:
    virtual void init() override;
    virtual void update(float) override;
};
END_NAMESPACE

#endif // CGAMESCENE_H
