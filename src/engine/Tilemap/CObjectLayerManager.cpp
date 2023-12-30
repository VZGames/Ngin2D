#include "CObjectLayerManager.h"

BEGIN_NAMESPACE(engine)
CObjectLayerManager::CObjectLayerManager()
{

}

void CObjectLayerManager::push(TmxObject &&object)
{
    m_objects.push_back(object);
}

std::vector<TmxObject> CObjectLayerManager::objects() const
{
    return m_objects;
}
END_NAMESPACE


