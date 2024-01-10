#include "CTileRenderer.h"
#include <matrix2D.h>
#include <Parser/TilemapParser/TmxFormat.h>

using namespace engine;
CTileRenderer::CTileRenderer()
{

}

void CTileRenderer::render(void *data)
{
    std::pair<TmxLayer, Matrix2D<int>> *layer = reinterpret_cast<std::pair<TmxLayer, Matrix2D<int>> *>(data);
}
