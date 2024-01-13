#ifndef A_RENDERER_H__
#define A_RENDERER_H__

#include <CommonDefine.h>

BEGIN_NAMESPACE(engine)
class ARenderer
{
public:
    virtual void render(void*, float) = 0;
};
END_NAMESPACE

#endif // A_RENDERER_H__
