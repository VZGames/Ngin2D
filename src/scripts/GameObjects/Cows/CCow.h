#ifndef CCOW_H
#define CCOW_H

#include "CommonDefine.h"
#include "Entity/CEntity.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SHealthComponent.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SBodyComponent.h"
#include "ComponentDef/SBox2DComponent.h"

BEGIN_NAMESPACE(script)
class CCow: public engine::CEntity
{
private:
    engine::SSpriteComponent          *m_sprite;
    engine::SHealthComponent          *m_health;
    engine::SPositionComponent        *m_position;
    engine::SBodyComponent            *m_body;
    engine::SBox2DComponent           *m_box2D;

public:
    CCow(float x, float y);
};
END_NAMESPACE

#endif // CCOW_H
