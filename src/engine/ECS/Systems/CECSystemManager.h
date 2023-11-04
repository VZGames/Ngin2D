#ifndef CECSYSTEMMANAGER_H
#define CECSYSTEMMANAGER_H

#include "CommonDefine.h"
#include "CollisionSystem/CCollisionSystem.h"
#include "MovementSystem/CMovementSystem.h"
#include "RenderSystem/CRenderSystem.h"

BEGIN_NAMESPACE(GameNgin)
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
public:
    static CECSystemManager *instance();

    void init();
    void update(std::vector<CEntity*> &entities, float dt);
};
END_NAMESPACE

#endif // CECSYSTEMMANAGER_H
