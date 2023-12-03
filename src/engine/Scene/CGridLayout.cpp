#include "CGridLayout.h"

BEGIN_NAMESPACE(engine)
CGridLayout::CGridLayout(float cellwith, int rows, int columns)
    :CGrid<int>(cellwith, cellwith, rows, columns)
{
}
END_NAMESPACE






