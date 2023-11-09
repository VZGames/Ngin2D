#ifndef CENEMY_H
#define CENEMY_H

#include "CommonDefine.h"
#include "Entity/CEntity.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SHealthComponent.h"
#include "ComponentDef/SPositionComponent.h"

BEGIN_NAMESPACE(Script)
class CEnemy: public engine::CEntity
{
private:
    engine::SSpriteComponent          *m_sprite;
    engine::SHealthComponent          *m_health;
    engine::SPositionComponent        *m_position;

public:
    CEnemy();

//    Implement CEntity's Interface
public:
    virtual void init() override;
    virtual void process(float) override;
};
END_NAMESPACE

#endif // CENEMY_H
