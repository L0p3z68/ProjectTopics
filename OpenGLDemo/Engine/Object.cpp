#include "Object.h"
#include <iostream>

Object::Object(Transform transform) : transform(transform) {}

Object::Object() : transform(Transform()) {}

Object::~Object() {}

void Object::AddComponent( Components* component) {
    component -> SetParent(this);
    components.emplace_back(component);
}

Transform Object::GetTransform() const {
    return transform;
}

void Object::SetTransform(Transform transform) {
    this->transform = transform;
}

void Object::Awake() {
    for (auto& component : components) {
        component->Awake();
    }
}

void Object::Start() {
    for (auto& component : components) {
        component->Start();
    }
}

void Object::Update(int deltaTime) {
    for (auto& component : components) {
        component->Update(deltaTime);
    }
}