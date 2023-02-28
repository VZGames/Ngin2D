#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include "ISystem.h"

namespace ngin2D {
class SystemManager: public ISystem
{
public:
    static SystemManager *instance();
private:
    SystemManager();
    static SystemManager *s_instance;

    // ISystem interface
public:
    virtual void init() override;
    virtual void update(float dt) override;
    virtual void render() override;
};
}

#endif // SYSTEMMANAGER_H
