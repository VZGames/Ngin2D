#include "CEnemy.h"
#include "Entity/CEntityManager.h"

BEGIN_NAMESPACE(Script)
CEnemy::CEnemy()
{
    float x = 100;
    float y = 200;
    engine::CEntityManager::instance()->createEntity(this);
    this->addComponent<engine::SBodyComponent>(x, y, b2BodyType::b2_dynamicBody)
        ->addComponent<engine::SPositionComponent>(x, y)
        ->addComponent<engine::SHealthComponent>(x)
        ->addComponent<engine::SSpriteComponent>("Animal", "./debug/assets/Characters/Cow.png", 32, 32, 3, 200)
        ->addComponent<engine::SBox2DComponent>(
            x,
            y,
            std::vector<b2Vec2>{
            {0,0},
            {32, 0},
            {32, 32},
            {0, 32}
        });
}

void CEnemy::init()
{
    m_body     = this->getComponent<engine::SBodyComponent>();
    m_position = this->getComponent<engine::SPositionComponent>();
    m_sprite   = this->getComponent<engine::SSpriteComponent>();
    m_health   = this->getComponent<engine::SHealthComponent>();
    m_box2D    = this->getComponent<engine::SBox2DComponent>();

    m_body->createFixture(&m_box2D->fixtureDef);
}

void CEnemy::process(float dt)
{
    UNUSED(dt)
}
END_NAMESPACE


