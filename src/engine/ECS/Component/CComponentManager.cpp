#include "CComponentManager.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(GameNgin)
CComponentManager *CComponentManager::s_instance = nullptr;
CComponentManager::CComponentManager()
{
    for (ComponentID i = 0; i < MAX_COMPONENT_ID; i++) {
        m_available_ids.push(i);
    }
}

CComponentManager *CComponentManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CComponentManager(): s_instance;
}

bool CComponentManager::createComponent(CComponent *newComponent)
{
    assert(m_component_count <= MAX_COMPONENT_ID && "The maximum number of entity creations has been reached");

    ComponentID _id = MIN_COMPONENT_ID;
    const char* compName = newComponent->name();
    if(compName == nullptr) return false;
    if(m_dictionary.find(compName) != m_dictionary.end())
    {
        _id = m_dictionary[compName];
    }
    else
    {
        _id = m_available_ids.front();
        newComponent->setId(_id);

        m_dictionary[compName] = _id;
        m_component_count++;

        m_available_ids.pop();
    }

    MORGAN_DEBUG("Created Component %s has ID %d", compName,  _id)
    return true;
}
END_NAMESPACE


