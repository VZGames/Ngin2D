#ifndef ENTITY_H
#define ENTITY_H

#include <bitset>
#include <memory>
#include <stdio.h>
#include <iostream>
#include "../Components/ComponentBase.h"

namespace ngin2D {
struct Entity
{
    EntityID id;
    ComponentSet components;

    template <typename T, typename... TArgs>
    T &addComponent(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        components[c->id] = 1;
        return *c;
    }
};
}

#endif // ENTITY_H
