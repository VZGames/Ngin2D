#ifndef CPLAYER_H
#define CPLAYER_H

#include "CommonDefine.h"
#include "Common/enums.h"

#include "Entity/CEntity.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SHealthComponent.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SBodyComponent.h"
#include "ComponentDef/SBox2DComponent.h"
#include "ComponentDef/SKeyInputComponent.h"

BEGIN_NAMESPACE(script)
class CPlayer: public engine::CEntity
{
private:
    engine::SSpriteComponent                        *m_sprite;
    engine::SHealthComponent                        *m_health;
    engine::SPositionComponent                      *m_position;
    engine::SCameraComponent                        *m_camera;
    engine::SMotionComponent                        *m_motion;
    engine::SBodyComponent                          *m_body;
    engine::SBox2DComponent                         *m_box2D;
    engine::SKeyInputComponent                      *m_keyInput;


public:
    CPlayer();

    void idle();
    void jump();
    void walk(E_MOVE_DIRECTION);
    void attach();
};
END_NAMESPACE

#endif // CPLAYER_H
