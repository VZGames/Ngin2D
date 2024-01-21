#include "CEntity.h"

using namespace engine;
CEntity::CEntity()
{
    m_class_name = __FUNCTION__;
    DBG("Init instance %s At address [%p]", m_class_name, this)
}

CEntity::~CEntity()
{
    for(auto component: m_components)
    {
        safeRelease(component.second);
    }
    m_components.clear();
    DBG("Release Instance %s At address [%p]", m_class_name, this);
}

EntityID CEntity::id() const
{
    return m_id;
}

void CEntity::setId(const EntityID &newId)
{
    m_id = newId;
}










