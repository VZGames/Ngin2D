#include "CComponent.h"

using namespace engine;
CComponent::CComponent(const char*name): m_name(name)
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





