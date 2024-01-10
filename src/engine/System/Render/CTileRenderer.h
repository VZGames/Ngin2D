#ifndef CTILERENDERER_H
#define CTILERENDERER_H

#include <CommonDefine.h>
#include "ARenderer.h"

BEGIN_NAMESPACE(engine)
class CTileRenderer: public ARenderer
{
public:
    CTileRenderer();

public:
    virtual void render(void *, float) override;
};
END_NAMESPACE

#endif // CTILERENDERER_H
