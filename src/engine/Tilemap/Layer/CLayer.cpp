#include "CLayer.h"
#include <algorithm>
BEGIN_NAMESPACE(engine)
CLayer::CLayer(): CGrid<int>(16, 16, 30, 30)
{
    this->resize(m_width, m_height);
}

CLayer CLayer::fromTmxLayer(TmxLayer tmxLayer)
{
    CLayer layer;
    layer.m_id = tmxLayer.id;

    return layer;
}
END_NAMESPACE


