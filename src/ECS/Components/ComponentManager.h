#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H


#include <queue>
#include <map>
#include <stdio.h>
#include "../../Defines/Defines.h"

namespace ngin2D {

class ComponentManager
{
public:
    static ComponentManager *instance();
    template<class T>
    ComponentID nextID()
    {
        const char* componentType = typeid(T).name();
        std::map<const char*, ComponentID>::iterator it;
        it = componentData.find(componentType);
        if(it == componentData.end())
        {
            ComponentID id = availableIDs.front();
            componentData[componentType] = id;
            availableIDs.pop();
            componentCount++;
        }
        return componentData[componentType];
    }

private:
    ComponentManager();

    static ComponentManager *s_instance;
    uint32_t componentCount = 0;
    std::queue<ComponentID> availableIDs;
    std::map<const char*, ComponentID> componentData;
};
}

#endif // COMPONENTMANAGER_H
