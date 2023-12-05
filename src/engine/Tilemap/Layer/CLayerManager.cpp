#include "CLayerManager.h"

BEGIN_NAMESPACE(engine)
CLayerManager::CLayerManager()
{

}

void CLayerManager::push(TmxLayer &&layer)
{
    m_layer.push(layer);
}
END_NAMESPACE

