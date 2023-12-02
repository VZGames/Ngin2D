#include "CGridLayout.h"

BEGIN_NAMESPACE(engine)
CGridLayout::CGridLayout(int rows, int columns)
    :Matrix2D<int>(rows, columns)
{

}


int CGridLayout::hash(int x, int y)
{
    int hashX = x % columns();
    int hashY = y % rows();
    return (hashY * columns()) + hashX;
}

void CGridLayout::insertEntity(uint32_t id, float x, float y)
{
    int pos = hash(static_cast<int>(x), static_cast<int>(y));
    this->setValueAt(pos, static_cast<int>(id));

    this->print();
}

void CGridLayout::removeEntity(uint32_t id)
{

}
END_NAMESPACE




