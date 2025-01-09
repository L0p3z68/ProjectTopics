#include "Rusher.h"

Rusher::Rusher(Object nav) : Object(nav)
{
	Window* window = Window::GetInstance();
	myRigidBody2D = new RigidBody2D(this, true, true);
	mySpriteRenderer = new SpriteRenderer("graphics/rusher.bmp", window, 4, 6, 0, this);
	myAnimator = new Animator(mySpriteRenderer);
}

void Rusher::Awake()
{
	AddComponent(myRigidBody2D);
	AddComponent(mySpriteRenderer);

	myAnimator->AddAnimation("Roaming", {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}, true, 10.f);

	AddComponent(myAnimator);

	Object::Awake();
}

void Rusher::Start()
{
	myAnimator->Play("Roaming");
	
	Object::Start();
}

void Rusher::Update(float deltaTime)
{
	timeToDie += deltaTime;
	if (timeToDie > 10.f) {
		Destroy();
	}
	myRigidBody2D->AddVelocity(Vector2(0.f, 100.f));
	Object::Update(deltaTime);
}

void Rusher::UpdateRender()
{
	Object::UpdateRender();
}
