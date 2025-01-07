#include "Transform.h"

Transform::Transform(Vector3 Position, Vector3 Rotation, Vector3 Scale) : position{ Position }, rotation{ Rotation }, scale{ Scale } {}

Transform::Transform(Vector3 Position) : position { Position }, rotation { Vector3(0.0f, 0.0f, 0.0f) }, scale{ Vector3(1.0f, 1.0f, 1.0f) }{}

Transform::Transform() : position{ Vector3(0.0f, 0.0f, 0.0f) }, rotation{ Vector3(0.0f, 0.0f, 0.0f) }, scale{ Vector3(1.0f, 1.0f, 1.0f) } {}

Vector3 Transform::GetPosition()
{
    return position;
}

Vector3 Transform::GetRotation()
{
    return rotation;
}

Vector3 Transform::GetScale()
{
    return scale;
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
