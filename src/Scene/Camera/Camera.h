#ifndef CAMERA_H
#define CAMERA_H

#include "SDL2/SDL.h"
#include "ECS/Entity/IEntity.h"
#include "ECS/Entity/EntityManager.h"
#include "Math/math2D.h"
#include "Defines/Defines.h"

namespace ngin2D {
class Camera
{
public:
    static Camera *instance();
    void update(float dt);
    void moveTo(Point2DF coord);
    void rotate();

    void setTarget(EntityID id);

    const SDL_FRect &viewport() const;

    Point2DF position() const;

private:
    Camera();
    static Camera *s_instance;
    SDL_FRect m_viewPort;
    Point2DF m_position;

    Entity *ptr_entity;

};
}

#endif // CAMERA_H
