#ifndef CGRID_H
#define CGRID_H

#include <matrix2D.h>

template<typename T>
class CGrid: public Matrix2D<T>
{
private:
    int m_cells;
    float m_x;
    float m_y;
    float m_cell_width;
    float m_cell_height;

public:
    CGrid()
        :m_cells(0), m_cell_width(0.0f), m_cell_height(0.0f){}

    CGrid(float cellwidth, float cellheight, int rows, int columns)
        :Matrix2D<T>(rows, columns), m_cell_width(cellwidth), m_cell_height(cellheight)
    {
        m_cells = (rows * columns);
    }

    int cells() { return m_cells; }

    int hash(int x, int y)
    {
        int hashX = x / m_cell_width;
        int hashY = y / m_cell_height;
        if(hashX < 0) hashX = 0;
        if(hashX > this->columns()) hashX = this->columns() - 1;
        if(hashY < 0) hashY = 0;
        if(hashY > this->rows()) hashY = this->rows() - 1;

        return (hashY * this->columns()) + hashX;
    }
    int hash(float x, float y)
    {
        return hash(static_cast<int>(x), static_cast<int>(y));
    }
};

#endif // CGRID_H
