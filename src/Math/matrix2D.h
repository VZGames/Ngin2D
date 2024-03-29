#ifndef MATRIX2D_H
#define MATRIX2D_H

#include "Utils/Utils.h"

template<typename T>
class Matrix2D
{
public:
    explicit Matrix2D(int height, int width) : height(height),width(width)
    {
        this->matrix = new T[height  *width];
    }

    Matrix2D(const Matrix2D<T> &copy) {
        this->matrix = copy.matrix;
    }

    T &at(int y, int x)
    {
        return this->matrix[(y  *width) + x];
    }

    T &at(int pos)
    {
        return this->matrix[pos];
    }

    int getHeight() const
    {
        return height;
    }
    int getWidth() const
    {
        return width;
    }

private:
    int height, width;
    T *matrix;
};

using Matrix2DI = Matrix2D<int>;
using Matrix2U = Matrix2D<unsigned int>;
using Matrix2F = Matrix2D<float>;
using Matrix2LF = Matrix2D<double>;

#endif // MATRIX2D_H
