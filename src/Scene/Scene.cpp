#include "Scene.h"
#include <algorithm>

namespace ngin2D {
Scene *Scene::s_instance = nullptr;
Scene *Scene::instance()
{
    return s_instance = (s_instance == nullptr)? new Scene(): s_instance;
}

void Scene::registerEntity(Entity *entity)
{
    this->entities.push_back(entity);
}

void Scene::deRegisterEntity(Entity *entity)
{
    std::vector<Entity*>::iterator it;
    it = std::find(entities.begin(), entities.end(), entity);
    this->entities.erase(it);
}

void Scene::registerSystem(ISystem *system)
{
    this->systems.push_back(system);
}

void Scene::deRegisterSystem(ISystem *system)
{
    std::vector<ISystem*>::iterator it;
    it = std::find_if(systems.begin(), systems.end(), [&](ISystem* sys)->bool{
        return sys == system;
    });
    this->systems.erase(it);
}

Scene::Scene()
{}
}
