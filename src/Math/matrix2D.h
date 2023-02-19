#ifndef MATRIX2D_H
#define MATRIX2D_H

template<typename T>
class Matrix2D
{
public:
    Matrix2D(int height, int width) : height(height),width(width)
    {
        this->matrix = new T[height * width];
    }

    Matrix2D(Matrix2D<T> &copy) {
        this->matrix = copy.matrix;
    }

    T &at(int y, int x)
    {
        return this->matrix[(y * width) + x];
    }

private:
    int height, width;
    T *matrix;
};

#endif // MATRIX2D_H
