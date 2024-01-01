#include "CCow.h"
#include "CEntityManager.h"
#include "Define/Assets/DefineCharacters.h"

BEGIN_NAMESPACE(script)
CCow::CCow(float x, float y)
{
    engine::CEntityManager::instance()->createEntity(this);
    m_position = this->addComponent<engine::SPositionComponent>(x, y);
    m_health = this->addComponent<engine::SHealthComponent>(100);
    m_sprite = this->addComponent<engine::SSpriteComponent>(__FUNCTION__, BASIC_COW, 32, 32, 3, 200);
    m_sprite->zOrder = 0;

    m_motion = this->addComponent<engine::SMotionComponent>(5);
    m_box = this->addComponent<engine::SBoxComponent>(E_BODY_TYPE::DYNAMIC, m_position->x, m_position->y);

    m_box->setVertex(4, 22);
    m_box->setVertex(6, 20);
    m_box->setVertex(22, 20);
    m_box->setVertex(24, 22);
    m_box->setVertex(24, 26);
    m_box->setVertex(22, 30);
    m_box->setVertex(6, 30);
    m_box->setVertex(4, 26);
    m_box->setAxes();
}

void CCow::setPosition(float x, float y)
{
    m_position->x = x;
    m_position->y = y;
}
END_NAMESPACE
