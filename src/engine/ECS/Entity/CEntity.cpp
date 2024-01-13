#include "CEntity.h"

using namespace engine;
CEntity::CEntity()
{
    m_class_name = __FUNCTION__;
}

CEntity::~CEntity()
{
    
}

EntityID CEntity::id() const
{
    return m_id;
}

void CEntity::setId(const EntityID &newId)
{
    m_id = newId;
}










