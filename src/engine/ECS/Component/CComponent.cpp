#include "CComponent.h"

using namespace engine;
CComponent::CComponent(const char* name)
{
    m_class_name = name;
    DBG("Init instance %s At address [%p]", m_class_name, this)
}

ComponentID CComponent::id() const
{
    return m_id;
}

void CComponent::setId(const ComponentID &newId)
{
    m_id = newId;
}




