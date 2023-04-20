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
    ~Scene();
    void loadEnemy();
    static Scene *s_instance;

    std::vector<IEntity*> m_enemies;
};
}


#endif // SCENE_H
