#include "CLayerManager.h"
#include <LoggerDefines.h>
#include "Render/CRenderSys.h"

using namespace engine;
CLayerManager *CLayerManager::s_instance = nullptr;
CLayerManager::CLayerManager()
{

}

CLayerManager* CLayerManager::instance()
{
    return s_instance = (s_instance == nullptr) ? new CLayerManager() : s_instance;
}

void CLayerManager::push(TmxLayer layer)
{
    m_layers.emplace_back(CLayer(layer));
    CRenderSys::instance()->addItem<CLayer>(&m_layers.back());
}

void CLayerManager::clear()
{
    m_layers.clear();
}

std::vector<CLayer> &CLayerManager::layers()
{
    return m_layers;
}





