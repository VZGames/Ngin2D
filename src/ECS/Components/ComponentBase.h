#ifndef COMPONENTBASE_H
#define COMPONENTBASE_H

#include "IComponent.h"
#include "ComponentManager.h"

namespace ngin2D {
template<class T>
struct ComponentBase: public IComponent
{
    ComponentID id = ComponentManager::instance()->nextID<T>();
};
}
#endif // COMPONENTBASE_H
