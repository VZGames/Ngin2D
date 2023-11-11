#ifndef CENEMY_H
#define CENEMY_H

#include "CommonDefine.h"
#include "Entity/CEntity.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SHealthComponent.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SBodyComponent.h"
#include "ComponentDef/SBox2DComponent.h"

BEGIN_NAMESPACE(Script)
class CEnemy: public engine::CEntity
{
private:
    engine::SSpriteComponent          *m_sprite;
    engine::SHealthComponent          *m_health;
    engine::SPositionComponent        *m_position;
    engine::SBodyComponent            *m_body;
    engine::SBox2DComponent           *m_box2D;

public:
    CEnemy();

//    Implement CEntity's Interface
public:
    virtual void init() override;
    virtual void process(float) override;
};
END_NAMESPACE

#endif // CENEMY_H
