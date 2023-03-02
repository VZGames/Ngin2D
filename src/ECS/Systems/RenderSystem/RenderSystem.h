#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "../ISystem.h"

namespace ngin2D {
class RenderSystem: public ISystem
{
public:
    RenderSystem();
    // ISystem interface
public:
    virtual void update(float dt) override;
    virtual void render() override;
};
}


#endif // RENDERSYSTEM_H
