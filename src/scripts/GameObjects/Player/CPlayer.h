#ifndef CPLAYER_H
#define CPLAYER_H

#include "CommonDefine.h"
#include "Entity/CEntity.h"
#include "Common/enums.h"

#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SHealthComponent.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SKeyInputComponent.h"

BEGIN_NAMESPACE(Script)
class CPlayer: public Ngin::CEntity
{
private:
    Ngin::SSpriteComponent          *m_sprite;
    Ngin::SHealthComponent          *m_health;
    Ngin::SPositionComponent        *m_position;
    Ngin::SCameraComponent          *m_camera;
    Ngin::SKeyInputComponent        *m_keyinput;
    Ngin::SMotionComponent          *m_motion;

public:
    CPlayer();

    void idle();
    void jump();
    void walk(MOVE_DIRECTION);
    void attach(CTRL_SLOTS);

//    Implement CEntity's Interface
public:
    virtual void init() override;
    virtual void process(float) override;
    virtual void handleKeyInput() override;
};
END_NAMESPACE

#endif // CPLAYER_H
