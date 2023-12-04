#include "CLayerManager.h"

BEGIN_NAMESPACE(engine)
CLayerManager::CLayerManager()
{

}

void CLayerManager::push(CLayer layer)
{
    m_layer.push(layer);
}
END_NAMESPACE

