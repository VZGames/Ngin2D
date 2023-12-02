#ifndef CGAMESCENE_H
#define CGAMESCENE_H

#include "CommonDefine.h"
#include "AScene.h"
#include "GameObjects/Cows/CCow.h"
#include "GameObjects/Player/CPlayer.h"
#include "CGridLayout.h"

BEGIN_NAMESPACE(script)
class CGameScene: public engine::AScene
{
    // game objects/entities
private:
    std::vector<engine::CEntity*>    m_entities;
    CPlayer player;
    CCow    cow;
    CCow    cow2;
    CCow    cow3;

    engine::CGridLayout m_layout;

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
