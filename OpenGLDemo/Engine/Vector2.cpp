#include "Vector2.h"

// Constructors
Vector2::Vector2(float x, float y) : X{ x }, Y{ y } {}
Vector2::Vector2() : X{ 0 }, Y{ 0 } {}

// Destructor
Vector2::~Vector2() {}

// Getters
float Vector2::GetX() const { return X; }
float Vector2::GetY() const { return Y; }

// Setters
void Vector2::SetX(float x) { X = x; }
void Vector2::SetY(float y) { Y = y; }
void Vector2::Set(float x, float y) { X = x; Y = y; }

// Static directional vectors
Vector2 Vector2::Up() { return Vector2(0.0f, 1.0f); }
Vector2 Vector2::Down() { return Vector2(0.0f, -1.0f); }
Vector2 Vector2::Right() { return Vector2(1.0f, 0.0f); }
Vector2 Vector2::Left() { return Vector2(-1.0f, 0.0f); }

// Operators
Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(X + other.GetX(), Y + other.GetY());
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(X - other.GetX(), Y - other.GetY());
}

Vector2 Vector2::operator*(float other) const {
    return Vector2(X * other, Y * other);
}

Vector2 Vector2::operator/(float other) const {
    if (other != 0.0f) {
        return Vector2(X / other, Y / other);
    }
    throw std::invalid_argument("Division by zero!");
}

bool Vector2::operator==(const Vector2& other) const {
    return X == other.GetX() && Y == other.GetY();
}

bool Vector2::operator!=(const Vector2& other) const {
    return !(*this == other);
}

// Normalize the vector
Vector2 Vector2::Normalize() const {
    float mag = std::sqrt(X * X + Y * Y);
    if (mag != 0.0f) {
        return Vector2(X / mag, Y / mag);
    }
    return Vector2();  // Return zero vector if magnitude is zero
}