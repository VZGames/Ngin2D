#ifndef MATRIX2D_H
#define MATRIX2D_H

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <assert.h>

template<typename T>
class Matrix2D
{
public:
    explicit Matrix2D(int rows, int columns) : m_rows(rows),m_columns(columns)
    {
        assert((rows  *columns > 0) && "Matrix size invalid");
        this->m_data = new T[rows  *columns];
    }

    // copy constructor
    Matrix2D(const Matrix2D<T> &copy)
    {
        this->m_columns = copy.m_columns;
        this->m_rows = copy.m_rows;
        this->m_data = copy.m_data;
    }

    // move constructor
    Matrix2D(Matrix2D<T> &&copy) noexcept
    {
        swap(*this, copy);
    }

    // Copy assignment operator
    Matrix2D<T> &operator=(const Matrix2D<T> &copy)
    {
        if (this != &copy)
        {
            Matrix2D<T> tmp(copy);
            swap(*this, tmp);
        }
        return *this;
    }

    // Move assignment operator
    Matrix2D<T>& operator=(Matrix2D<T>&& other) noexcept
    {
        swap(*this, other);
        return *this;
    }

    T &at(int y, int x)
    {
        assert((x < m_rows && y < m_columns) && "Index invalid");
        return this->m_data[(y  * m_columns) + x];
    }

    T &at(int pos)
    {
        assert((pos < (m_rows * m_columns)) && "Index invalid");
        return this->m_data[pos];
    }

    void setValueAt(int pos, T value)
    {
        this->m_data[pos] = value;
    }

    int rows() const
    {
        return m_rows;
    }
    int columns() const
    {
        return m_columns;
    }

    void print()
    {
        for (int row = 0; row < m_rows; row++)
        {
            // read line
            for (int col = 0; col < m_columns; col++)
            {
                std::cout << at(row, col) << " ";
            }
            std::cout << "\n";
        }
    }
    static Matrix2D<T> fromString(const char *cstr, int rows, int columns)
    {
        std::string str(cstr);
        std::istringstream ss(str);
        Matrix2D<T> data(rows, columns);

        // read rows
        for (int row = 0; row < rows; row++)
        {
            // read lines
            std::string line;
            for (int col = 0; col < columns; col++)
            {
                std::getline(ss, line, ',');
                data.at(row, col) = std::stoi(line);
            }
        }
        return data;
    }

    friend void swap(Matrix2D<T>& first, Matrix2D<T>& second) noexcept {
        using std::swap;

        swap(first.m_rows, second.m_rows);
        swap(first.m_columns, second.m_columns);
        swap(first.m_data, second.m_data);
    }
private:
    int m_rows, m_columns;
    T *m_data;
};

using Matrix2DI = Matrix2D<int>;
using Matrix2U = Matrix2D<unsigned int>;
using Matrix2F = Matrix2D<float>;
using Matrix2LF = Matrix2D<double>;

#endif // MATRIX2D_H
