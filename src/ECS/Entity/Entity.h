#ifndef ENTITY_H
#define ENTITY_H

#include <bitset>
#include <memory>
#include <vector>
#include <stdio.h>
#include <iostream>
#include "../Components/ComponentBase.h"

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
        T *c(new T(std::forward<TArgs>(mArgs)...));
        componentBitset[c->id] = 1;
        components[typeName] = std::move(c);
        return *c;
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
