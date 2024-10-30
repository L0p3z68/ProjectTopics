#pragma once
#include <stdexcept>
#include <cmath>

class Vector2 {
private:
    float X;
    float Y;

public:
    // Constructors
    Vector2(float x, float y);
    Vector2();

    // Destructor
    ~Vector2();

    // Getters
    float GetX() const;
    float GetY() const;

    // Setters
    void SetX(float x);
    void SetY(float y);
    void Set(float x, float y);

    // Static directional vectors
    static Vector2 Up();
    static Vector2 Down();
    static Vector2 Right();
    static Vector2 Left();

    // Operators
    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(float other) const;
    Vector2 operator/(float other) const;

    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;

    // Normalize the vector
    Vector2 Normalize() const;
};