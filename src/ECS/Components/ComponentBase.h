#ifndef COMPONENTBASE_H
#define COMPONENTBASE_H

#include "ComponentManager.h"

namespace ngin2D {
template<class T>
struct ComponentBase
{
    ComponentID id = ComponentManager::instance()->nextID<T>();
};
}
#endif // COMPONENTBASE_H
