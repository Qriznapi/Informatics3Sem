#pragma once
#include "complex.hpp"
#include <iostream>
#include <cmath>

struct Vector2f {
    float x;
    float y;

    Vector2f(float xx = 0.0f, float yy = 0.0f) {
        x = (xx), y = (yy);
    }
};

// Operator overload for addition
Vector2f operator+(const Vector2f& a, const Vector2f& b) {
    return Vector2f(a.x + b.x, a.y + b.y);
}

// Operator overload for subtraction
Vector2f operator-(const Vector2f& a, const Vector2f& b) {
    return Vector2f(a.x - b.x, a.y - b.y);
}

Vector2f operator*(const Vector2f& v, float scalar) {
    return Vector2f(v.x * scalar, v.y * scalar);
}

Vector2f operator*(Vector2f& v1, Vector2f& v2) {
    return Vector2f(v1.x * v2.x, v1.y * v2.y);
}
Vector2f operator/(const Vector2f& v, float scalar) {
    return Vector2f(v.x / scalar, v.y / scalar);
}

// Operator overload for equality
bool operator==(const Vector2f& a, const Vector2f& b) {
    return (a.x == b.x && a.y == b.y);
}

// Operator overload for inequality
bool operator!=(const Vector2f& a, const Vector2f& b) {
    return !(a == b);
}

// Operator overload for addition assignment
Vector2f& operator+=(Vector2f& a, const Vector2f& b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

// Operator overload for subtraction assignment
Vector2f& operator-=(Vector2f& a, const Vector2f& b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

// Operator overload for scalar multiplication assignment
Vector2f& operator*=(Vector2f& v, float scalar) {
    v.x *= scalar;
    v.y *= scalar;
    return v;
}

Vector2f& operator/=(Vector2f& v, float scalar) {
    v.x /= scalar;
    v.y /= scalar;
    return v;
}

Vector2f& operator*=(Vector2f& v, int scalar) {
    v.x *= scalar;
    v.y *= scalar;
    return v;
}

Vector2f& operator/=(Vector2f& v, int scalar) {
    v.x /= scalar;
    v.y /= scalar;
    return v;
}

Vector2f operator+(Vector2f a) 
{
    return a;
}

Vector2f operator-(Vector2f a) {
    return Vector2f(-a.x, -a.y);
}

std::istream& operator>>(std::istream& in, Vector2f& vector) {
    in >> vector.x >> vector.y;
    return is;
}

std::ostream& operator<<(std::ostream& out, const Vector2f& vector) {
    out << "(" << vector.x << ", " << vector.y << ")";
    return out;
}
