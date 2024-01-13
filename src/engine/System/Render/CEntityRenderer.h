#ifndef C_ENTITY_RENDERER_H
#define C_ENTITY_RENDERER_H

#include <CommonDefine.h>
#include "ARenderer.h"

BEGIN_NAMESPACE(engine)
class CEntityRenderer: public ARenderer
{
public:
    CEntityRenderer();

public:
    virtual bool render(void*, float) override;
};
END_NAMESPACE

#endif // C_ENTITY_RENDERER_H
