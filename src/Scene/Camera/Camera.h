#ifndef CAMERA_H
#define CAMERA_H

#include "SDL2/SDL.h"
#include "ECS/Entity/IEntity.h"
#include "ECS/Entity/EntityManager.h"
#include "Defines/Defines.h"

namespace ngin2D {
class Camera
{
public:
    static Camera *instance();
    void update(float dt);
    void moveTo();
    void setTarget(EntityID id);

    const SDL_Rect &viewport() const;

private:
    Camera();
    static Camera *s_instance;
    SDL_Rect m_viewport;

    Entity *ptr_entity;

};
}

#endif // CAMERA_H
