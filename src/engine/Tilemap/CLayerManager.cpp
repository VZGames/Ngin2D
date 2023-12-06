#include "CLayerManager.h"
#include "matrix2D.h"
#include "LoggerDefines.h"
#include "CRenderSys.h"

BEGIN_NAMESPACE(engine)
CLayerManager::CLayerManager()
{

}

void CLayerManager::push(TmxLayer &&layer)
{
    m_layers.push_back(layer);
}

void CLayerManager::update(float dt)
{
    for(const TmxLayer &layer: m_layers)
    {

    }
}

void CLayerManager::render()
{
    for(const TmxLayer &layer: m_layers)
    {
        Matrix2D<int> matrix = Matrix2D<int>::fromString(layer.data->content, layer.height, layer.width);
        for(int r = 0; r < matrix.rows(); r++)
        {
            for(int c = 0; c < matrix.columns(); c++)
            {
                int firstgid = 0;
                int tileID = matrix.at(r, c);

//                CRenderSys::instance()->drawTile();
            }
        }
    }
}
END_NAMESPACE



