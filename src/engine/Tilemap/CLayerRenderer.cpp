#include "CLayerRenderer.h"
#include "matrix2D.h"
#include "LoggerDefines.h"
#include "CTexture2DManager.h"

BEGIN_NAMESPACE(engine)
CLayerRenderer::CLayerRenderer()
{

}


void CLayerRenderer::render(TmxLayer& layer)
{
    for(int r = 0; r < layer.data->matrix.rows(); r++)
    {
        for(int c = 0; c < layer.data->matrix.columns(); c++)
        {
            int tileId = layer.data->matrix.at(r, c);
            if(!layer.data->tileMark[tileId].has_value()) continue;
            const char* tilesetName = layer.data->tileMark[tileId].value();
            CTexture2DManager::instance()->drawTile(tilesetName, Point2DF(layer.x, layer.y), 32, 32, r, c);
        }
    }

}
END_NAMESPACE



