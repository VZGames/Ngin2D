#ifndef CRENDER_H
#define CRENDER_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class CRender
{
private:
    CRender();
    static CRender *s_instance;
public:
    static CRender *instance();

    void drawFrame(CEntity*);
};
END_NAMESPACE

#endif // CRENDER_H
