#ifndef A_RENDERER_H__
#define A_RENDERER_H__

#include <CommonDefine.h>

BEGIN_NAMESPACE(engine)
class ABase;
class ARenderer
{
protected:
    std::unordered_map<ABase*, bool> m_red_flag;
public:
    virtual bool render(ABase*, float) = 0;
};
END_NAMESPACE

#endif // A_RENDERER_H__
