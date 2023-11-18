#include "CCow.h"
#include "CEntityManager.h"

BEGIN_NAMESPACE(script)
CCow::CCow(float x, float y)
{
    engine::CEntityManager::instance()->createEntity(this);
    m_body          = this->addComponent<engine::SBodyComponent>(b2BodyType::b2_dynamicBody);
    m_position      = this->addComponent<engine::SPositionComponent>(x, y);
    m_health        = this->addComponent<engine::SHealthComponent>(100);
    m_sprite        = this->addComponent<engine::SSpriteComponent>(__FUNCTION__, "./debug/assets/Characters/Cow.png", 32, 32, 3, 200);
    m_box2D         = this->addComponent<engine::SBox2DComponent>(
            16,
            12,
            std::vector<b2Vec2>{{8,24},{40, 24},{40, 24},{40, 24}}
            );
}

END_NAMESPACE
