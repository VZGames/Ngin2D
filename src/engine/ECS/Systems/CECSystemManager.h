#ifndef CECSYSTEMMANAGER_H
#define CECSYSTEMMANAGER_H

#include "CommonDefine.h"
#include "CollisionSystem/CCollisionSystem.h"
#include "MovementSystem/CMovementSystem.h"
#include "RenderSystem/CRenderSystem.h"
#include "KeyInputSystem/CKeyInputSystem.h"

BEGIN_NAMESPACE(Ngin)
class CEntity;
class AECSystem;

class CECSystemManager
{
private:
    CECSystemManager();
    static CECSystemManager                   *s_instance;
    std::vector<AECSystem*>                   m_systems;

    CCollisionSystem                           m_collision_system;
    CMovementSystem                            m_movement_system;
    CRenderSystem                              m_render_system;
    CKeyInputSystem                            m_keyinput_system;
public:
    static CECSystemManager *instance();

    void init();
    void update(std::vector<CEntity*> &entities, float dt);
    void render();
};
END_NAMESPACE

#endif // CECSYSTEMMANAGER_H
