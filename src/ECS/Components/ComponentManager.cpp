#include "ComponentManager.h"

namespace ngin2D {
ComponentManager *ComponentManager::s_instance = nullptr;

ComponentManager *ComponentManager::instance()
{
    return s_instance = (s_instance == nullptr)? new ComponentManager():s_instance;
}

void ComponentManager::appendReference(IComponent *ref)
{
    componentPtrs.push_back(ref);
}

ComponentManager::ComponentManager()
{
    for (ComponentID i = 0; i < MAX_COMPONENTS; i++) {
        availableIDs.push(i);
    }
}

const std::vector<IComponent *> &ComponentManager::getComponentPtrs() const
{
    return componentPtrs;
}

const std::map<const char *, ComponentID> &ComponentManager::getComponentData() const
{
    return componentData;
}

}
