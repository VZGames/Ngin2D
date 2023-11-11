#include "CEnemy.h"
#include "Entity/CEntityManager.h"

BEGIN_NAMESPACE(Script)
CEnemy::CEnemy()
{
    engine::CEntityManager::instance()->createEntity(this);
    this->addComponent<engine::SBodyComponent>(b2BodyType::b2_dynamicBody, new b2PolygonShape())
        ->addComponent<engine::SPositionComponent>(100, 200)
        ->addComponent<engine::SHealthComponent>(100)
        ->addComponent<engine::SSpriteComponent>("Animal", "./debug/assets/Characters/Cow.png", 32, 32, 3, 200);
}

void CEnemy::init()
{
    m_body     = this->getComponent<engine::SBodyComponent>();
    m_position = this->getComponent<engine::SPositionComponent>();
    m_sprite   = this->getComponent<engine::SSpriteComponent>();
    m_health   = this->getComponent<engine::SHealthComponent>();

    m_body->define.position.Set(m_position->x, m_position->y);

    b2PolygonShape *shape = (b2PolygonShape *)m_body->fixtureDef.shape;
    b2Vec2 vertices[4];
    vertices[0].Set(0,0);
    vertices[1].Set(m_sprite->frameWidth, 0);
    vertices[2].Set(m_sprite->frameWidth, m_sprite->frameHeight);
    vertices[3].Set(0,m_sprite->frameHeight);

    shape->Set(vertices, 4);
    shape->SetAsBox(m_sprite->frameWidth/2, m_sprite->frameHeight/2);
}

void CEnemy::process(float dt)
{
    UNUSED(dt)
}
END_NAMESPACE


