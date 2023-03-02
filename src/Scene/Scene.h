#ifndef SCENE_H
#define SCENE_H

#include "../ECS/ECS.h"

namespace ngin2D {
class Scene
{
public:
    static Scene *instance();

    void registerEntity(Entity *entity);

    void deRegisterEntity(Entity *entity);

    void registerSystem(ISystem *system);

    void deRegisterSystem(ISystem *system);

private:
    Scene();
    static Scene *s_instance;
    std::vector<Entity*> entities;
    std::vector<ISystem*> systems;
};
}


#endif // SCENE_H
