#ifndef CRENDERSYS_H
#define CRENDERSYS_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class CRenderSys
{
private:
    CRenderSys();
    static CRenderSys *s_instance;
public:
    static CRenderSys *instance();

    void drawFrame(CEntity*);
};
END_NAMESPACE

#endif // CRENDERSYS_H
