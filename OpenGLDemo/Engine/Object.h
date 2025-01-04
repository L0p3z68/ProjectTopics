#pragma once
#include "BaseScript.h"
#include "Transform.h"
#include "Components.h"
#include <vector>

class Object : public BaseScript {
private:
    Transform transform;

    std::vector<Components*> components;

public:
    int x;

    Object(Transform transform);
    Object();
    ~Object();

    void AddComponent( Components* component);
    Transform GetTransform() const;
    void SetTransform(Transform transform);

    void Awake();
    void Start();
    void Update(int deltaTime);
};
