#include "Explotion.h"

Explotion::Explotion(Object nav) : Object(nav)
{
	Window* window = Window::GetInstance();
	mySpriteRenderer = new SpriteRenderer("graphics/explode64.bmp", window, 5, 2, 0, this);
	myAnimator = new Animator(mySpriteRenderer);
}

void Explotion::Awake()
{
	AddComponent(mySpriteRenderer);

	myAnimator->AddAnimation("Idle", { 0, 1, 2, 3, 4, 5}, false, 10.f);

	AddComponent(myAnimator);

	Object::Awake();
}

void Explotion::Start()
{
	myAnimator->Play("Idle");

	Object::Start();
}

void Explotion::Update(float deltaTime)
{
	deathTimer += deltaTime;
	if (deathTimer > 1.f) {
		Destroy();
	}
	Object::Update(deltaTime);
}

void Explotion::UpdateRender()
{
	Object::UpdateRender();
}
