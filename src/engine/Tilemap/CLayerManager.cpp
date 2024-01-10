#include "CLayerManager.h"
#include <LoggerDefines.h>

using namespace engine;
CLayerManager *CLayerManager::s_instance = nullptr;
CLayerManager::CLayerManager()
{

}

CLayerManager* CLayerManager::instance()
{
    return s_instance = (s_instance = nullptr) ? new CLayerManager() : s_instance;
}

void CLayerManager::push(TmxLayer &&layer)
{
    Matrix2D<int> matrix = Matrix2D<int>::fromString(layer.data->content, layer.height, layer.width);
    m_layers.push_back(std::make_pair(layer, matrix));
}

void CLayerManager::clear()
{
    m_layers.clear();
}

std::vector<std::pair<TmxLayer, Matrix2D<int>>> &CLayerManager::layers()
{
    return m_layers;
}





