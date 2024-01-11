#ifndef C_TILE_RENDERER_H
#define C_TILE_RENDERER_H

#include <CommonDefine.h>
#include "ARenderer.h"

BEGIN_NAMESPACE(engine)
class CTileRenderer: public ARenderer
{
public:
    CTileRenderer();

public:
    virtual void render(ItemData, float) override;
};
END_NAMESPACE

#endif // C_TILE_RENDERER_H
