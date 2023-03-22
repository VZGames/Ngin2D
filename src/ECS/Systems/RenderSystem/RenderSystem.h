#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "ECS/Systems/ISystem.h"

namespace ngin2D {
class RenderSystem: public ISystem
{
public:
    RenderSystem();
    // ISystem interface
public:
    virtual void init() override;
    virtual void update(float dt) override;
    virtual void render() override;
};
}


#endif // RENDERSYSTEM_H
