#include "Object.h"
#include "Scene.h"
#include <iostream>

Object::Object(std::string tag, Transform transform) : transform(transform), tag(tag) {}

Object::Object() : transform(Transform()) {}

Object::~Object() {
    for (size_t i = 0; i < components.size(); i++)
    {
        components[i]->~Components();
    }
    //components.~vector();
    //delete scene;
    scene = nullptr;
}

void Object::AddComponent( Components* component) {
    component -> SetParent(this);
    components.emplace_back(component);
}

Transform Object::GetTransform() const {
    return transform;
}

std::string Object::GetTag()
{
    return tag;
}

void Object::SetTransform(Transform transform) {
    this->transform = transform;
}

void Object::AddToPosition(Vector3 position)
{
    this->transform.SetPosition(transform.GetPosition() + position);
}

void Object::Destroy()
{
    scene->Destroy(this);
}

void Object::Instantiate(Object* object)
{
    scene->AddObject(object);
    object->Awake();
    object->Start();
}

void Object::OnTrigger(Object* object)
{
    
}

void Object::SetScene(Scene* scene)
{
    this->scene = scene;
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

void Object::Update(float deltaTime) {
    for (auto& component : components) {
        component->Update(deltaTime);
    }
}

void Object::UpdateRender()
{
    for (auto& component : components) {
        component->UpdateRender();
    }
}
