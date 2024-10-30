#include "Transform.h"

Transform::Transform(Vector3 Position, Vector3 Rotation, Vector3 Scale) : position{ Position }, rotation{ Rotation }, scale{ Scale } {}
Transform::Transform() : position{ Vector3(0.0f, 0.0f, 0.0f) }, rotation{ Vector3(0.0f, 0.0f, 0.0f) }, scale{ Vector3(1.0f, 1.0f, 1.0f) } {}
