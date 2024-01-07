#include "CObjectLayerManager.h"
#include "CBroadPhaseCulling.h"
#include "Alias.h"

using namespace engine;
CObjectLayerManager::CObjectLayerManager()
{

}

void CObjectLayerManager::push(TmxObject &&object)
{
    CPolygonShape shape;
    shape.pushVertex(object.x, object.y);
    shape.pushVertex(object.x + object.width, object.y + object.y);
    
    m_box.push_back(std::move(shape));
    m_objects.push_back(object);

    CBroadPhaseCulling::instance()->insert(MAX_ENTITY_ID + object.id, object.x, object.y);
}

const std::vector<TmxObject> *CObjectLayerManager::objects() const
{
    return &m_objects;
}

const std::vector<CPolygonShape> *CObjectLayerManager::box() const
{
    return &m_box;
}

bool CObjectLayerManager::checkCollision(AShape *other, Vector2D<float> &mtv)
{
    for(CPolygonShape &box: m_box)
    {
        bool collided = AShape::checkCollision(&box, other, mtv);
        if(collided)
        {
            return true;
        }
    }
    return false;
}




