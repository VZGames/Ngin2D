#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <cmath>

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
    Vector2D(const Vector2D<T> &p_Copy) {
        this->x = p_Copy.x;
        this->y = p_Copy.y;
    }
    Vector2D() : x(0), y(0) {}
    Vector2D(T p_X, T p_Y) : x(p_X), y(p_Y) {}

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

    friend Vector2D<T> &operator+(Vector2D<T> &p_A, const Vector2D<T> &p_B)
    {
        return p_A.Add(p_B);
    }
    friend Vector2D<T> &operator-(Vector2D<T> &p_A, const Vector2D<T> &p_B)
    {

        return p_A.Subtract(p_B);
    }
    friend Vector2D<T> &operator*(Vector2D<T> &p_A, const Vector2D<T> &p_B)
    {

        return p_A.Multiply(p_B);
    }
    friend Vector2D<T> &operator/(Vector2D<T> &p_A, const Vector2D<T> &p_B)
    {

        return p_A.Divide(p_B);
    }

    Vector2D<T> &operator+=(const Vector2D<T> &p_B)
    {
        return this->Add(p_B);
    }
    Vector2D<T> &operator-=(const Vector2D<T> &p_B)
    {
        return this->Subtract(p_B);
    }
    Vector2D<T> &operator*=(const Vector2D<T> &p_B)
    {
        return this->Multiply(p_B);
    }
    Vector2D<T> &operator/=(const Vector2D<T> &p_B)
    {
        return this->Divide(p_B);
    }

    Vector2D<T> &operator*(T &i)
    {
        this->x *= i;
        this->y *= i;
        return *this;
    }

    Vector2D<T> &operator*=(T &i)
    {
        this->x *= i;
        this->y *= i;
        return *this;
    }

    Vector2D<T> &operator=(const Vector2D<T> &p_B)
    {
        this->x = p_B.x;
        this->y = p_B.y;
        return *this;
    }

    float scalar() const
    {
        return (float)std::sqrt(std::pow(x,2) + std::pow(y,2));
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

using Vector2I = Vector2D<int>;
using Vector2U = Vector2D<unsigned int>;
using Vector2F = Vector2D<float>;
using Vector2LF = Vector2D<double>;

#endif // VECTOR2D_H
