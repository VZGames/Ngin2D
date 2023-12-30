#include "CObjectLayerManager.h"
#include "CBroadPhaseCulling.h"
#include "Alias.h"

BEGIN_NAMESPACE(engine)
CObjectLayerManager::CObjectLayerManager()
{

}

void CObjectLayerManager::push(TmxObject &&object)
{
    CPolygonShape shape;
    shape.pushVertex(object.x, object.y);
    shape.pushVertex(object.x + object.width, object.y + object.y);

    CBroadPhaseCulling::instance()->insert(MAX_ENTITY_ID + object.id, object.x, object.y);

    m_box.push_back(std::move(shape));
    m_objects.push_back(object);
}

const std::vector<TmxObject> *CObjectLayerManager::objects() const
{
    return &m_objects;
}

const std::vector<CPolygonShape> *CObjectLayerManager::box() const
{
    return &m_box;
}
END_NAMESPACE



