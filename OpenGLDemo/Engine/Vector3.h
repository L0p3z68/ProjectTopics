#pragma once
#include <stdexcept>
#include <cmath>
#include "Vector2.h"  // Include Vector2 header file

class Vector3 {
private:
    float X;
    float Y;
    float Z;

public:
    // Constructors
    Vector3(float x, float y, float z);
    Vector3();

    // Destructor
    ~Vector3();

    // Getters
    float GetX() const;
    float GetY() const;
    float GetZ() const;

    // Setters
    void SetX(float x);
    void SetY(float y);
    void SetZ(float z);
    void Set(float x, float y, float z);

    // Operators
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(float other) const;
    Vector3 operator/(float other) const;

    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;

    // Normalize the vector
    Vector3 Normalize() const;

    // Convert to Vector2
    Vector2 ToVector2() const;
};