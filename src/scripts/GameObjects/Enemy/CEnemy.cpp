#include "CEnemy.h"
#include "Entity/CEntityManager.h"

BEGIN_NAMESPACE(script)
CEnemy::CEnemy(float x, float y)
{
    engine::CEntityManager::instance()->createEntity(this);
    {
        m_body      = this->addComponent<engine::SBodyComponent>(b2BodyType::b2_dynamicBody);
    }
    {
        m_position  = this->addComponent<engine::SPositionComponent>(x, y);
    }
    {
        m_health    = this->addComponent<engine::SHealthComponent>(100);
    }
    {
        m_sprite    = this->addComponent<engine::SSpriteComponent>(__FUNCTION__, "./debug/assets/Characters/slime.png", 32, 32, 7, 200);
        m_sprite->row = 2;
    }
    {
        m_box2D     = this->addComponent<engine::SBox2DComponent>(
            16,
            16,
            std::vector<b2Vec2>{{8,16},{24, 16},{24, 24},{8, 24}}
            );
    }
}

END_NAMESPACE


