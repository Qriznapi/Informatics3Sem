#pragma once
#include "complex.hpp"
#include <iostream>
#include <cmath>

class Vector2f {
public:
    float x;
    float y;

    Vector2f() : x(0), y(0) {}
    Vector2f(float x, float y) : x(x), y(y) {}

    Vector2f operator+(const Vector2f& other) const {
        return Vector2f(x + other.x, y + other.y);
    }

    Vector2f operator-(const Vector2f& other) const {
        return Vector2f(x - other.x, y - other.y);
    }

    Vector2f operator*(float scalar) const {
        return Vector2f(x * scalar, y * scalar);
    }

    bool operator==(const Vector2f& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2f& other) const {
        return !(*this == other);
    }

    Vector2f& operator+=(const Vector2f& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2f& operator-=(const Vector2f& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2f& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2f& vector) {
        os << "(" << vector.x << ", " << vector.y << ")";
        return os;
    }
};
