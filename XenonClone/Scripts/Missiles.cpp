#include "Missiles.h"
#include "Explotion.h"

Missiles::Missiles(Object nav) : Object(nav)
{
	Window* window = Window::GetInstance();
	myRigidBody2D = new RigidBody2D(this, true, false);
	mySpriteRenderer = new SpriteRenderer("graphics/missile.bmp", window, 4, 4, 1, this);
	myAnimator = new Animator(mySpriteRenderer);
}

void Missiles::Awake()
{
	AddComponent(myRigidBody2D);
	AddComponent(mySpriteRenderer);

	myAnimator->AddAnimation("Idle", { 1, 3}, true, 10.f);

	AddComponent(myAnimator);

	Object::Awake();
}

void Missiles::Start()
{
	myAnimator->Play("Idle");

	Object::Start();
}

void Missiles::Update(float deltaTime)
{
	myRigidBody2D->AddVelocity(Vector2(.0f, -100.f));
	Object::Update(deltaTime);
}

void Missiles::UpdateRender()
{
	Object::UpdateRender();
}

void Missiles::OnTrigger(Object* object)
{
	if (object->GetTag() == "Enemy") {
		Instantiate(new Explotion(Object("", transform)));
		object->Destroy();
		Destroy();
	}
}


