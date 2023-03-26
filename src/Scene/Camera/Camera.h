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
    void moveTo(Point2DI coord);

    void setTarget(EntityID id);

    const SDL_Rect &viewport() const;

    Point2DI position() const;

private:
    Camera();
    static Camera *s_instance;
    SDL_Rect m_viewPort;
    Point2DI m_position;

    Entity *ptr_entity;

};
}

#endif // CAMERA_H
