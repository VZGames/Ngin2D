#ifndef CENEMY_H
#define CENEMY_H

#include "CommonDefine.h"
#include "Entity/CEntity.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SHealthComponent.h"
#include "ComponentDef/SPositionComponent.h"

BEGIN_NAMESPACE(Script)
class CEnemy: public Ngin::CEntity
{
private:
    Ngin::SSpriteComponent          *m_sprite;
    Ngin::SHealthComponent          *m_health;
    Ngin::SPositionComponent        *m_position;

public:
    CEnemy();

//    Implement CEntity's Interface
public:
    virtual void motionUpdate(float) override;
};
END_NAMESPACE

#endif // CENEMY_H
