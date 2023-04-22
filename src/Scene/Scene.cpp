#include "Scene.h"
#include <algorithm>
#include <future>

namespace ngin2D {
Scene *Scene::s_instance = nullptr;
Scene *Scene::instance()
{
    return s_instance = (s_instance == nullptr)? new Scene(): s_instance;
}

Scene::Scene()
{
}

Scene::~Scene()
{
    for(auto enemy: m_enemies)
    {
        safeDeleteArray(enemy);
    }

    m_enemies.clear();
}

void Scene::updateEnemies(float dt)
{

}

void Scene::loadEnemies()
{
    Slime *slime1 = new Slime();
    slime1->init();
    slime1->data()->getComponent<SpawnComponent>()->position.setX(10);

    Slime *slime2 = new Slime();
    slime2->init();
    slime2->data()->getComponent<SpawnComponent>()->position.setX(200);

    Slime *slime3 = new Slime();
    slime3->init();
    slime3->data()->getComponent<SpawnComponent>()->position.setX(90);
}

void Scene::init()
{
    loadEnemies();
    Player::instance()->init();
    Camera::instance()->setTarget(Player::instance()->getID());

    SystemManager::instance()->addSystem<MovementSystem>();
    SystemManager::instance()->addSystem<CollisionSystem>();
    SystemManager::instance()->addSystem<SpawnSystem>();
    SystemManager::instance()->addSystem<RenderSystem>();
    SystemManager::instance()->init();
}

void Scene::update(float dt)
{
    auto f = std::async(std::launch::deferred, [&](float dt){
        for (IEntity *entity: m_enemies) {
           ((Slime*)entity)->update(dt);
        }
    }, dt);

    f.get();
    Player::instance()->update(dt);
    Camera::instance()->update(dt);
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
