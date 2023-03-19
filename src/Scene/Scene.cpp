#include "Scene.h"
#include <algorithm>
#include "../Event/Events.h"

namespace ngin2D {
Scene *Scene::s_instance = nullptr;
Scene *Scene::instance()
{
    return s_instance = (s_instance == nullptr)? new Scene(): s_instance;
}

Scene::Scene()
{
}

void Scene::init()
{
    Player::instance();


    SystemManager::instance()->addSystem<MovementSystem>();
    SystemManager::instance()->addSystem<SpawnSystem>();
    SystemManager::instance()->addSystem<RenderSystem>();
    SystemManager::instance()->addSystem<CameraSystem>();
    SystemManager::instance()->init();
}

void Scene::update(float dt)
{
    SystemManager::instance()->update(dt);
}

void Scene::render()
{
    SystemManager::instance()->render();
}

void Scene::handleEvents()
{
    Player::instance()->handleKeyEvent();
    Player::instance()->handleMouseEvent();
}
}
