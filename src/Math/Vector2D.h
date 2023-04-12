#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <cmath>
#include <vector>
#include "Utils/Utils.h"

template <typename T>
class Vector2D
{
private:
    Vector2D<T> &Add(const Vector2D<T> &vec)
    {
        this->x += vec.x;
        this->y += vec.y;
        return *this;
    }
    Vector2D<T> &Subtract(const Vector2D<T> &vec)
    {
        this->x -= vec.x;
        this->y -= vec.y;
        return *this;
    }
    Vector2D<T> &Multiply(const Vector2D<T> &vec)
    {
        this->x *= vec.x;
        this->y *= vec.y;
        return *this;
    }
    Vector2D<T> &Divide(const Vector2D<T> &vec)
    {
        this->x /= vec.x;
        this->y /= vec.y;
        return *this;
    }

public:
    T x;
    T y;
    Vector2D(const Vector2D<T> &Copy) {
        this->x = Copy.x;
        this->y = Copy.y;
    }
    Vector2D() : x(0), y(0) {}
    Vector2D(T X, T Y) : x(X), y(Y) {}

    Vector2D<T> &Ones()
    {
        this->x = static_cast<T>(1);
        this->y = static_cast<T>(1);
        return *this;
    }
    Vector2D<T> &Zeros()
    {
        this->x = static_cast<T>(0);
        this->y = static_cast<T>(0);
        return *this;
    }

    friend Vector2D<T> &operator+(Vector2D<T> &A, const Vector2D<T> &B)
    {
        return A.Add(B);
    }
    friend Vector2D<T> &operator-(Vector2D<T> &A, const Vector2D<T> &B)
    {

        return A.Subtract(B);
    }
    friend Vector2D<T> &operator*(Vector2D<T> &A, const Vector2D<T> &B)
    {

        return A.Multiply(B);
    }
    friend Vector2D<T> &operator/(Vector2D<T> &A, const Vector2D<T> &B)
    {
        return A.Divide(B);
    }

    Vector2D<T> &operator+=(const Vector2D<T> &B)
    {
        return this->Add(B);
    }
    Vector2D<T> &operator-=(const Vector2D<T> &B)
    {
        return this->Subtract(B);
    }
    Vector2D<T> &operator*=(const Vector2D<T> &B)
    {
        return this->Multiply(B);
    }
    Vector2D<T> &operator/=(const Vector2D<T> &B)
    {
        return this->Divide(B);
    }


    Vector2D<T> operator*(const Vector2D<T> &B)
    {
        Vector2D<T> vec = *this;
        return vec->Multiply(B);
    }

    Vector2D<T> operator*(const T &i)
    {
        Vector2D<T> vec = *this;
        vec.x *= i;
        vec.y *= i;
        return vec;
    }

    Vector2D<T> operator*=(T i)
    {
        Vector2D<T> vec = *this;
        vec.x *= i;
        vec.y *= i;
        return vec;
    }

    Vector2D<T> &operator*=(T &i)
    {
        this->x *= i;
        this->y *= i;
        return *this;
    }


    Vector2D<T> &operator/=(T &i)
    {
        this->x /= i;
        this->y /= i;
        return *this;
    }

    Vector2D<T> &operator/=(T i)
    {
        this->x /= i;
        this->y /= i;
        return *this;
    }

    Vector2D<T> &operator=(const Vector2D<T> &B)
    {
        this->x = B.x;
        this->y = B.y;
        return *this;
    }

    Vector2D<T> &perp()
    {
        swap(this->x, this->y);
        this->Multiply(Vector2D<T>(-1, 1));
        return *this;
    }

    float magnitude() const
    {
        return (float)std::sqrt(std::pow(x,2) + std::pow(y,2));
    }

    float dotProduct(const Vector2D<T> &vec)
    {
        return this->x * vec.x + this->y * vec.y;
    }

    static float dotProduct(const Vector2D<T> &A, const Vector2D<T> &B)
    {
        return A.x * B.x + A.y * B.y;
    }

    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }
    friend std::ostream &operator<<(std::ostream &out, const Vector2D &vec)
    {
        out << "(" << vec.x << ", " << vec.y << ")\n";
        return out;
    }
};

using Vector2DI = Vector2D<int>;
using Vector2DU = Vector2D<unsigned int>;
using Vector2DF = Vector2D<float>;
using Vector2DLF = Vector2D<double>;

using ListVector2DI = std::vector<Vector2DI>;
using ListVector2DU = std::vector<Vector2DU>;
using ListVector2DF = std::vector<Vector2DF>;
using ListVector2DLF = std::vector<Vector2DF>;

#endif // VECTOR2D_H
