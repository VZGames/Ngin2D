#include "CLayerRenderer.h"
#include "matrix2D.h"
#include "LoggerDefines.h"
#include "CTexture2DManager.h"

BEGIN_NAMESPACE(engine)
CLayerRenderer::CLayerRenderer()
{

}


void CLayerRenderer::render(const std::unordered_map<const char*, TmxTileSet> &,TmxLayer &layer, Matrix2D<int>&& matrix)
{
    for(int r = 0; r < matrix.rows(); r++)
    {
        for(int c = 0; c < matrix.columns(); c++)
        {
            int tileId = matrix.at(r, c);
            // need: tileset name, cell in tileset

//            CTexture2DManager::instance()->drawTile(tilesetName, Point2DF(layer.x * c * 16, layer.y * r * 16), 16, 16, r, c);
        }
    }

}
END_NAMESPACE



