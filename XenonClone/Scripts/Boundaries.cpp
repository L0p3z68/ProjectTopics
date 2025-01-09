#include "Boundaries.h"

Boundaries::Boundaries(Object nav) : Object(nav)
{
	Window* window = Window::GetInstance();
	myRigidBody2D = new RigidBody2D(this, false, false);
	mySpriteRenderer = new SpriteRenderer("graphics/bblogo.bmp", window, 1, 1, 0, this);
}

void Boundaries::Awake()
{
	AddComponent(myRigidBody2D);
	AddComponent(mySpriteRenderer);

	Object::Awake();
}

void Boundaries::Start()
{
	Object::Start();
}

void Boundaries::Update(float deltaTime)
{
	Object::Update(deltaTime);
}
