#ifndef SCENE_H
#define SCENE_H

#include "../ECS/ECS.h"
#include "../ECS/Entity/Dynamic/Player/Player.h"

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
};
}


#endif // SCENE_H
