#include "CComponent.h"

BEGIN_NAMESPACE(Ngin)
CComponent::CComponent()
{}

ComponentID CComponent::id() const
{
    return m_id;
}

void CComponent::setId(const ComponentID &newId)
{
    m_id = newId;
}

const char *CComponent::name() const
{
    return m_name;
}
END_NAMESPACE




