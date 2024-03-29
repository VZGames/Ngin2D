#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H


#include <queue>
#include <map>
#include <stdio.h>
#include <cassert>
#include "Defines/Defines.h"
#include "Math/math2D.h"

namespace ngin2D {

class ComponentManager
{
public:
    static ComponentManager *instance();
    template<class T>
    ComponentID nextID()
    {
        const char *typeName = typeid(T).name();
        std::map<const char*, ComponentID>::iterator it;
        it = componentData.find(typeName);
        if(it == componentData.end())
        {
            ComponentID id = availableIDs.front();
            componentData[typeName] = id;
            availableIDs.pop();
            componentCount++;
        }
        return componentData[typeName];
    }

    template<class T>
    bool hasComponentType(ComponentSet &components)
    {
        const char *typeName = typeid(T).name();
        if(components[componentData[typeName]] == 1)
        {
            return true;
        }
        return false;

    }

    const std::map<const char *, ComponentID> &getComponentData() const;


private:
    ComponentManager();

    static ComponentManager *s_instance;
    uint32_t componentCount = 0;
    std::queue<ComponentID> availableIDs;

    std::map<const char*, ComponentID> componentData;
};
}

#endif // COMPONENTMANAGER_H
