#ifndef ENTITY_H
#define ENTITY_H

#include <bitset>
#include <memory>
#include <vector>
#include <stdio.h>
#include <iostream>
#include "ECS/Components/ComponentBase.h"

namespace ngin2D {
struct Entity
{
    EntityID id;
    ComponentSet componentBitset;
    std::map<const char*, IComponent*> components;


    template<typename T, typename... TArgs>
    T &addComponent(TArgs&&... mArgs)
    {
        const char *typeName = typeid(T).name();
        assert(components.find(typeName) == components.end() && "Adding component more than once.");

        T *c(new T(std::forward<TArgs>(mArgs)...));
        componentBitset[c->id] = 1;
        components[typeName] = std::move(c);
        return *c;
    }

    template<typename T>
    bool destroyComponent()
    {
        const char *typeName = typeid(T).name();
        auto it = components.find(typeName);
        if(it == components.end())
            return 0;
        components.erase(it);
        return 1;

    }

    template<typename T>
    T *getComponent() const
    {
        const char *typeName = typeid(T).name();
        if(components.find(typeName) == components.end())
            return nullptr;
        return (T*)components.at(typeName);
    }

    bool operator==(const Entity &right)
    {
        return id == right.id;
    }

    bool operator==(const Entity *right)
    {
        return this->id == right->id;
    }
};
}

#endif // ENTITY_H
