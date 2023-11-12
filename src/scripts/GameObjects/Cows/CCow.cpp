#include "CCow.h"
#include "CEntityManager.h"

BEGIN_NAMESPACE(script)
CCow::CCow(float x, float y)
{
    engine::CEntityManager::instance()->createEntity(this);
    this->addComponent<engine::SBodyComponent>(x, y, b2BodyType::b2_dynamicBody)
        ->addComponent<engine::SPositionComponent>(x, y)
        ->addComponent<engine::SHealthComponent>(100)
        ->addComponent<engine::SSpriteComponent>("Animal", "./debug/assets/Characters/Cow.png", 32, 32, 3, 200)
        ->addComponent<engine::SBox2DComponent>(
            16,
            16,
            std::vector<b2Vec2>{
                                {0,0},
                                {32, 0},
                                {32, 32},
                                {0, 32}}
            );
}

void CCow::init()
{
    m_body     = this->getComponent<engine::SBodyComponent>();
    m_position = this->getComponent<engine::SPositionComponent>();
    m_sprite   = this->getComponent<engine::SSpriteComponent>();
    m_health   = this->getComponent<engine::SHealthComponent>();
    m_box2D    = this->getComponent<engine::SBox2DComponent>();

    m_body->createFixture(&m_box2D->fixtureDef);
}

void CCow::process(float)
{

}
END_NAMESPACE
