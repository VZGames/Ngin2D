#ifndef SYSTEM_H
#define SYSTEM_H

namespace ngin2D {
class ISystem
{
public:
    virtual void init() = 0;
    virtual void update(float dt) = 0;
    virtual void render() = 0;
};
}
#endif // SYSTEM_H
