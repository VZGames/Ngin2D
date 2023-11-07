#ifndef CRENDER_H
#define CRENDER_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(Ngin)
class CEntity;
class CRender
{
private:
    CRender();
    static CRender *s_instance;
public:
    static CRender *instance();

    void drawEntity(CEntity*);
};
END_NAMESPACE

#endif // CRENDER_H
