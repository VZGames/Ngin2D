#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include "ISystem.h"

namespace ngin2D {
class SystemManager: public ISystem
{
public:
    static SystemManager *instance();
    template<class T>
    void registerSystem(T &system)
    {

    }
    // ISystem interface
public:
    virtual void init() override;
    virtual void update(float dt) override;
    virtual void render() override;

private:
    SystemManager();
    static SystemManager *s_instance;


};
}

#endif // SYSTEMMANAGER_H
