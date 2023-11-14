#ifndef CECSYSTEMMANAGER_H
#define CECSYSTEMMANAGER_H

#include "CommonDefine.h"
#include "ThreadPool/CThreadPool.h"
#include "CollisionSystem/CCollisionSystem.h"
#include "MovementSystem/CMovementSystem.h"
#include "SpriteSystem/CSpriteSystem.h"
#include "KeyInputSystem/CKeyInputSystem.h"
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
    CThreadPool                                *m_threadPool;
    std::vector<AECSystem*>                    m_systems;

    CCollisionSystem                           m_collision_system;
    CMovementSystem                            m_movement_system;
    CSpriteSystem                              m_render_system;
    CKeyInputSystem                            m_keyinput_system;
    CCameraSystem                              m_camera_system;
    CMotionSystem                              m_motion_system;

public:
    static CECSystemManager *instance();

    void init(std::vector<CEntity*>&);
    void update(float dt);
};
END_NAMESPACE

#endif // CECSYSTEMMANAGER_H
