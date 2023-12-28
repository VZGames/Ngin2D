#include "AScene.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(engine)

const char *AScene::id() const
{
    return m_id;
}

const Vector2D<float> &AScene::boundary() const
{
    return m_boundary;
}

void AScene::setBoundary(const Vector2D<float> &newBoundary)
{
    m_boundary = newBoundary;
}
END_NAMESPACE




