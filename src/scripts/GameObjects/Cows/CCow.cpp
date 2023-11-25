#include "CCow.h"
#include "CEntityManager.h"

BEGIN_NAMESPACE(script)
CCow::CCow(float x, float y)
{
    engine::CEntityManager::instance()->createEntity(this);
    m_position      = this->addComponent<engine::SPositionComponent>(x, y);
    m_health        = this->addComponent<engine::SHealthComponent>(100);
    m_sprite        = this->addComponent<engine::SSpriteComponent>(__FUNCTION__, "./debug/assets/Characters/Cow.png", 32, 32, 3, 200);
    m_box           = this->addComponent<engine::SBoxComponent>(E_BODY_TYPE::DYNAMIC, m_position->x, m_position->y);

    m_box->setVertex(Vector2DF(4, 20));
    m_box->setVertex(Vector2DF(24, 20));
    m_box->setVertex(Vector2DF(24, 28));
    m_box->setVertex(Vector2DF(4, 28));
    m_box->setAxes();
}

END_NAMESPACE
