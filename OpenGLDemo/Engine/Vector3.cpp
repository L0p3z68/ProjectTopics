#include "Vector3.h"

// Constructors
Vector3::Vector3(float x, float y, float z) : X{ x }, Y{ y }, Z{ z } {}
Vector3::Vector3() : X{ 0 }, Y{ 0 }, Z{ 0 } {}

// Destructor
Vector3::~Vector3() {}

void Vector3::Set(float x, float y, float z) { X = x; Y = y; Z = z; }

// Operators
Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(X + other.X, Y + other.Y, Z + other.Z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(X - other.X, Y - other.Y, Z - other.Z);
}

Vector3 Vector3::operator*(float other) const {
    return Vector3(X * other, Y * other, Z * other);
}

Vector3 Vector3::operator/(float other) const {
    if (other != 0.0f) {
        return Vector3(X / other, Y / other, Z / other);
    }
    throw std::invalid_argument("Division by zero!");
}

bool Vector3::operator==(const Vector3& other) const {
    return X == other.X && Y == other.Y && Z == other.Z;
}

bool Vector3::operator!=(const Vector3& other) const {
    return !(*this == other);
}

// Normalize the vector
Vector3 Vector3::Normalize() const {
    float mag = std::sqrt(X * X + Y * Y + Z * Z);
    if (mag != 0.0f) {
        return Vector3(X / mag, Y / mag, Z / mag);
    }
    return Vector3();  // Return zero vector if magnitude is zero
}

// Convert to Vector2
Vector2 Vector3::ToVector2() const {
    return Vector2(X, Y);
}
