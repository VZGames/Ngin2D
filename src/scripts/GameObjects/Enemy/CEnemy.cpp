#include "CEnemy.h"
#include "Entity/CEntityManager.h"
#include "Component/ComponentDef/SSpriteComponent.h"
#include "Component/ComponentDef/SHealthComponent.h"
#include "Component/ComponentDef/SPositionComponent.h"

BEGIN_NAMESPACE(Script)
CEnemy::CEnemy()
{
    Ngin::CEntityManager::instance()->createEntity(this);
    this->addComponent<Ngin::SPositionComponent>(300 * this->id(), 200)
        ->addComponent<Ngin::SHealthComponent>(100)
        ->addComponent<Ngin::SSpriteComponent>("Animal", "./debug/assets/Characters/Cow.png", 32, 32, 3, 200);
}

void CEnemy::motionUpdate(float dt)
{
    UNUSED(dt)
    m_position = this->getComponent<Ngin::SPositionComponent>();
    m_sprite   = this->getComponent<Ngin::SSpriteComponent>();

    Offset offset = Ngin::CCamera::instance()->offset();
    m_position->x -= offset.getX();
    m_position->y -= offset.getY();
    MORGAN_DEBUG("%f %f ", m_position->x, m_position->y)
}
END_NAMESPACE

