#include "CLayerManager.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(engine)
CLayerManager::CLayerManager()
{

}

void CLayerManager::push(TmxLayer &&layer)
{
    m_layers.push_back(layer);
}

std::vector<TmxLayer> CLayerManager::layers() const
{
    return m_layers;
}
END_NAMESPACE




