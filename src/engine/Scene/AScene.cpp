#include "AScene.h"

BEGIN_NAMESPACE(engine)

const char *AScene::id() const
{
    return m_id;
}

void AScene::setBoundaryLimit(float left, float top, float right, float bottom)
{
    m_boundaryLimit.top_left.x = left;
    m_boundaryLimit.top_left.y = top;
    m_boundaryLimit.bottom_right.x = right;
    m_boundaryLimit.bottom_right.y = bottom;
}

const Rect<float> *AScene::boundaryLimit() const
{
    return &m_boundaryLimit;
}
END_NAMESPACE



