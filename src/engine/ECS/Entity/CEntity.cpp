#include "CEntity.h"

BEGIN_NAMESPACE(engine)
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









