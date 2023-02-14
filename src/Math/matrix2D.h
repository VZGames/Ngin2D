#ifndef MATRIX2D_H
#define MATRIX2D_H

template<typename T>
class Matrix2D
{
public:
    Matrix2D(int row, int col) : row(row),col(col)
    {
        matrix = new T[row * col];
    }

    Matrix2D(Matrix2D<T> &copy) {
        matrix = copy;
    }

private:
    int row, col;
    T *matrix;
};

#endif // MATRIX2D_H
