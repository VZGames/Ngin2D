#include "CGridLayout.h"

BEGIN_NAMESPACE(engine)
CGridLayout::CGridLayout(float cellwith, int rows, int columns)
    :CGrid<std::stack<int>>(cellwith, cellwith, rows, columns)
{
}

void CGridLayout::insertTileForLayer(int tileId, float x, float y)
{
    int position = hash(x, y);;
    this->at(position).push(tileId);
}

END_NAMESPACE







