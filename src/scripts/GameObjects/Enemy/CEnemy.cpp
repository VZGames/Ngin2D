#include "CEnemy.h"
#include "CMouseEvent.h"
#include "Entity/CEntityManager.h"

BEGIN_NAMESPACE(script)
CEnemy::CEnemy(float x, float y)
{
    engine::CEntityManager::instance()->createEntity(this);
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
        m_box       = this->addComponent<engine::SBoxComponent>(E_BODY_TYPE::DYNAMIC, m_position->x, m_position->y);
        m_box->setVertex(8, 16);
        m_box->setVertex(24, 16);
        m_box->setVertex(24, 25);
        m_box->setVertex(8, 25);
        m_box->setAxes();
    }
    {
        engine::CMouseEvent::instance()->registerMouse(E_MOUSE_EVENT::MOUSE_CLICKED, &CEnemy::kill, this);
    }
}

void CEnemy::kill()
{

}

END_NAMESPACE



