#ifndef CPLAYER_H
#define CPLAYER_H

#include "CommonDefine.h"
#include "Entity/CEntity.h"

#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SHealthComponent.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SKeyInputComponent.h"

BEGIN_NAMESPACE(Script)
class CPlayer: public engine::CEntity
{
private:
    engine::SSpriteComponent          *m_sprite;
    engine::SHealthComponent          *m_health;
    engine::SPositionComponent        *m_position;
    engine::SCameraComponent          *m_camera;
    engine::SKeyInputComponent        *m_keyinput;
    engine::SMotionComponent          *m_motion;



public:
    CPlayer();

    void idle();
    void jump();
    void walk();
    void attach();

//    Implement CEntity's Interface
public:
    virtual void init() override;
    virtual void process(float) override;
    virtual void handleKeyInput() override;
};
END_NAMESPACE

#endif // CPLAYER_H
