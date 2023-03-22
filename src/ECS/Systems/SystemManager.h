#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <map>
#include <memory>
#include <cassert>
#include "ECS/Systems/Systems.h"

namespace ngin2D {
class SystemManager: public ISystem
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

    // ISystem interface
public:
    virtual void init() override;
    virtual void update(float dt) override;
    virtual void render() override;

private:
    SystemManager();
    static SystemManager *s_instance;
    std::map<const char*, ISystem*> systems;
};
}

#endif // SYSTEMMANAGER_H
