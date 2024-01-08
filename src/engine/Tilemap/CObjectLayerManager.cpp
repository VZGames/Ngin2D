#include "CObjectLayerManager.h"
#include "CBroadPhaseCulling.h"
#include "Alias.h"

using namespace engine;
CObjectLayerManager::CObjectLayerManager()
{
    m_broad_phase_culling = CBroadPhaseCulling::instance();
}

void CObjectLayerManager::push(TmxObject &&object)
{
    CPolygonShape shape;
    shape.pushVertex(object.x, object.y);
    shape.pushVertex(object.x + object.width, object.y + object.y);
    
    m_box.push_back(std::move(shape));
    m_objects.push_back(object);

    m_broad_phase_culling->insert(object.id + MAX_ENTITY_ID, object.x, object.x);
    int currentCell = m_broad_phase_culling->hash(object.x, object.x);
    DBG("%d", currentCell)
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
    int currentCell = m_broad_phase_culling->hash(other->center().x, other->center().y);
    if (currentCell >= m_broad_phase_culling->cells()) return false;

    for (int i = 0; i < static_cast<int>(m_objects.size()); i++)
    {
        if (m_broad_phase_culling->at(currentCell).find(m_objects.at(i).id + MAX_ENTITY_ID) == m_broad_phase_culling->at(currentCell).end())
        {
            continue;
        }
        else
        {
            bool collided = AShape::checkCollision(&m_box[i], other, mtv);
            if(collided)
            {
                return true;
            }
        }
        
    }
    return false;
}




