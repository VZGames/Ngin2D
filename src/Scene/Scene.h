#ifndef SCENE_H
#define SCENE_H

#include "../ECS/ECS.h"

namespace ngin2D {
class Scene
{
public:
    static Scene *instance();
    void registerEntity(Entity *entity)
    {
        this->entities.push_back(entity);
    }

    void registerSystem(ISystem* system)
    {
       this->systems.push_back(system);
    }

private:
    Scene();
    static Scene *s_instance;
    std::vector<Entity*> entities;
    std::vector<ISystem*> systems;
};
}


#endif // SCENE_H
