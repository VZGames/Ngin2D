#include "CLayerManager.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(engine)
CLayerManager::CLayerManager()
{

}

void CLayerManager::push(TmxLayer &&layer)
{
    Matrix2D<int> matrix = Matrix2D<int>::fromString(layer.data->content, layer.height, layer.width);
    m_layers.push_back(std::make_pair(layer, matrix));
}

std::vector<std::pair<TmxLayer, Matrix2D<int>>> CLayerManager::layers() const
{
    return m_layers;
}
END_NAMESPACE




