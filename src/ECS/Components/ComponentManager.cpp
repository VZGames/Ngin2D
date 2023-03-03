#include "ComponentManager.h"

namespace ngin2D {
ComponentManager *ComponentManager::s_instance = nullptr;

ComponentManager *ComponentManager::instance()
{
    return s_instance = (s_instance == nullptr)? new ComponentManager():s_instance;
}

ComponentManager::ComponentManager()
{
    for (ComponentID i = 0; i < MAX_COMPONENTS; i++) {
        availableIDs.push(i);
    }
}

const std::map<const char *, ComponentID> &ComponentManager::getComponentData() const
{
    return componentData;
}

}
