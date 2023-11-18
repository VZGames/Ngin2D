#ifndef CECSYSTEMMANAGER_H
#define CECSYSTEMMANAGER_H

#include "CommonDefine.h"
#include "ThreadPool/CThreadPool.h"
#include "CollisionSystem/CCollisionSystem.h"
#include "MovementSystem/CMovementSystem.h"
#include "SpriteSystem/CSpriteSystem.h"
#include "CameraSystem/CCameraSystem.h"
#include "MotionSystem/CMotionSystem.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class AScene;
class AECSystem;

class CECSystemManager
{
private:
    CECSystemManager();
    static CECSystemManager                    *s_instance;
    std::vector<AECSystem*>                    m_systems;

    CMovementSystem                            m_movement_system;
    CCameraSystem                              m_camera_system;
    CMotionSystem                              m_motion_system;
    CCollisionSystem                           m_collision_system;
    CSpriteSystem                              m_render_system;

public:
    static CECSystemManager *instance();

    void init();
    void update(float dt);
};
END_NAMESPACE

#endif // CECSYSTEMMANAGER_H
