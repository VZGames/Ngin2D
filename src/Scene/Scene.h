#ifndef SCENE_H
#define SCENE_H

#include "ECS/ECS.h"
#include "Event/Events.h"
#include "Camera/Camera.h"
#include "ECS/Entity/Entities.h"

namespace ngin2D {
class Scene
{
public:
    static Scene *instance();

    void init();
    void update(float dt);
    void render();
    void handleEvents();


private:
    Scene();
    static Scene *s_instance;

//    tmp
    Slime slimes[2];
};
}


#endif // SCENE_H
