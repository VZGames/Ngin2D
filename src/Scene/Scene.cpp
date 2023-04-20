#include "Scene.h"
#include <algorithm>

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
    for (IEntity *entity: m_enemies) {
        if(entity == nullptr)
        {
            LOG_INFO("XXXXXXXXXXXx");
        }
        entity->update(dt);
    }
}

void Scene::loadEnemies()
{
    for (int i = 0; i < SLIME_COUNT; ++i) {
        Slime *slime = new Slime();
        slime->init();
        auto spawn   = slime->data()->getComponent<SpawnComponent>();
        spawn->position.setX(i * 100);
        m_enemies.push_back(slime);
    }
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
    updateEnemies(dt);
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
