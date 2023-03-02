#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <map>
#include <memory>
#include <cassert>
#include "ISystem.h"
#include "Systems.h"

namespace ngin2D {
class SystemManager
{
public:
    static SystemManager *instance();
    template<class T>
    T *addSystem()
    {
        const char *typeName = typeid(T).name();

        assert(systems.find(typeName) == systems.end() && "Adding system more than once.");

        auto system = new T();
        systems[typeName] = system;
        return system;
    }

private:
    SystemManager();
    static SystemManager *s_instance;
    std::map<const char*, ISystem*> systems;

};
}

#endif // SYSTEMMANAGER_H
