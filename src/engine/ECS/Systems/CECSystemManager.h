#ifndef CECSYSTEMMANAGER_H
#define CECSYSTEMMANAGER_H

#include "CommonDefine.h"
#include "CollisionSystem/CCollisionSystem.h"
#include "MovementSystem/CMovementSystem.h"
#include "RenderSystem/CRenderSystem.h"
#include "KeyInputSystem/CKeyInputSystem.h"
#include "CameraSystem/CCameraSystem.h"

BEGIN_NAMESPACE(Ngin)
class CEntity;
class AScene;
class AECSystem;

class CECSystemManager
{
private:
    CECSystemManager();
    static CECSystemManager                    *s_instance;
    std::vector<AECSystem*>                    m_systems;

    CCollisionSystem                           m_collision_system;
    CMovementSystem                            m_movement_system;
    CRenderSystem                              m_render_system;
    CKeyInputSystem                            m_keyinput_system;
    CCameraSystem                              m_camera_system;
public:
    static CECSystemManager *instance();

    void init(std::vector<CEntity*>&);
    void update(float dt);
    void render();
};
END_NAMESPACE

#endif // CECSYSTEMMANAGER_H
