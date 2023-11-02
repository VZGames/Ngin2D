#include "CEntity.h"

BEGIN_NAMESPACE(GameNgin)
CEntity::CEntity()
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

END_NAMESPACE








