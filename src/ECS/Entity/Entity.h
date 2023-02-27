#ifndef ENTITY_H
#define ENTITY_H

#include <bitset>
#include <memory>
#include <stdio.h>
#include "../../Defines/Defines.h"
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
        components[c->id] = true;
        //        printf("Component Type %s with id: %d\n", typeid(T).name(), c->id);
        return *c;
    }
};
}

#endif // ENTITY_H
