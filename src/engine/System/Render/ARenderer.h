#ifndef A_RENDERER_H__
#define A_RENDERER_H__

#include <CommonDefine.h>

BEGIN_NAMESPACE(engine)
typedef struct 
{
    void *data = nullptr;
    const char* class_name = "";
} ItemData;

class ARenderer
{
public:
    virtual void render(ItemData, float) = 0;
};
END_NAMESPACE

#endif // A_RENDERER_H__
