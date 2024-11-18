#include "Transform.h"

Transform::Transform(Vector3 Position, Vector3 Rotation, Vector3 Scale) : position{ Position }, rotation{ Rotation }, scale{ Scale } {}

Transform::Transform() : position{ Vector3(0.0f, 0.0f, 0.0f) }, rotation{ Vector3(0.0f, 0.0f, 0.0f) }, scale{ Vector3(1.0f, 1.0f, 1.0f) } {}

Vector3 Transform::GetPosition()
{
    return Vector3();
}

Vector3 Transform::GetRotation()
{
    return Vector3();
}

Vector3 Transform::GetScale()
{
    return Vector3();
}

void Transform::SetPosition(Vector3 pos)
{
    position = pos;
}

void Transform::SetRotation(Vector3 rot)
{
    rotation = rot;
}

void Transform::SetScale(Vector3 sca)
{
    scale = sca;
}
