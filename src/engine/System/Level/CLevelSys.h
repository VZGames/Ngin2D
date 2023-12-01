#ifndef CLEVELSYS_H
#define CLEVELSYS_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class CLevelSys
{
private:
    CLevelSys();
    static CLevelSys* s_instance;
public:
    static CLevelSys* instance();
    void update(float dt);
};
END_NAMESPACE

#endif // CLEVELSYS_H
