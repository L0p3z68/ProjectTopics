#include "Object.h"

Object::Object(Transform transform)
{
	transform = transform;
}

Object::Object()
{
	transform = Transform();
}

void Object::AddComponent(Components component)
{
	components.push_back(component);
}

void Object::Awake()
{
	for (size_t i = 0; i < components.size(); ++i)
	{
		components[i].Awake();
	}
}

void Object::Start()
{
	for (size_t i = 0; i < components.size(); ++i)
	{
		components[i].Start();
	}
}

void Object::Update(int deltaTime)
{
	for (size_t i = 0; i < components.size(); ++i)
	{
		components[i].Update(deltaTime);
	}
}

Object::~Object()
{

	components.~vector();
}
