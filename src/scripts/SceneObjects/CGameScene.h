#ifndef CGAMESCENE_H
#define CGAMESCENE_H

#include <CommonDefine.h>
#include "AScene.h"
#include "GameObjects/Cows/CCow.h"
#include "GameObjects/Player/CPlayer.h"
#include "CTilemap.h"

BEGIN_NAMESPACE(script)
class CGameScene: public engine::AScene
{
    // game objects/entities
private:
    CPlayer player;
    CCow    cow;
    CCow    cow2;
    CCow    cow3;
    std::vector<engine::CEntity*>    m_entities;

    engine::CTilemap    *m_tilemap = nullptr;

public:
    CGameScene();
    ~CGameScene();

    // AScene interface
public:
    virtual void init() override;
    virtual void update(float) override;
    virtual void render() override;
};
END_NAMESPACE

#endif // CGAMESCENE_H
