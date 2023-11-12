#include "CEnemy.h"
#include "Entity/CEntityManager.h"

BEGIN_NAMESPACE(script)
CEnemy::CEnemy(float x, float y)
{
    engine::CEntityManager::instance()->createEntity(this);
    this->addComponent<engine::SBodyComponent>(b2BodyType::b2_dynamicBody)
        ->addComponent<engine::SPositionComponent>(x, y)
        ->addComponent<engine::SHealthComponent>(100)
        ->addComponent<engine::SSpriteComponent>(__FUNCTION__, "./debug/assets/Characters/slime.png", 32, 32, 7, 200)
        ->addComponent<engine::SBox2DComponent>(
            32,
            32,
            std::vector<b2Vec2>{{0,0},{32, 0},{32, 32},{0, 32}}
            );
}

void CEnemy::init()
{
    m_body     = this->getComponent<engine::SBodyComponent>();
    m_position = this->getComponent<engine::SPositionComponent>();
    m_sprite   = this->getComponent<engine::SSpriteComponent>();
    m_health   = this->getComponent<engine::SHealthComponent>();
    m_box2D    = this->getComponent<engine::SBox2DComponent>();

    m_sprite->row = 2;
    m_body->createFixture(&m_box2D->fixtureDef);
}

void CEnemy::process(float dt)
    {
        UNUSED(dt)
    }
END_NAMESPACE


