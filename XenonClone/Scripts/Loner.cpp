#include "Loner.h"
#include "EnemyProjectile.h"

Loner::Loner(Object nav) : Object(nav)
{
	Window* window = Window::GetInstance();
	myRigidBody2D = new RigidBody2D(this, true, true);
	mySpriteRenderer = new SpriteRenderer("graphics/LonerA.bmp", window, 4, 4, 0, this);
	myAnimator = new Animator(mySpriteRenderer);
}

void Loner::Awake()
{
	AddComponent(myRigidBody2D);
	AddComponent(mySpriteRenderer);

	myAnimator->AddAnimation("Roaming", { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }, true, 10.f);

	AddComponent(myAnimator);

	Object::Awake();
}

void Loner::Start()
{
	myAnimator->Play("Roaming");

	Object::Start();
}

void Loner::Update(float deltaTime)
{
	cooldownShoot += deltaTime;
	timeToDie+= deltaTime;
	if (timeToDie > 14.f) {
		Destroy();
	}

	if (cooldownShoot > 3.0f) {
		Instantiate(new EnemyProjectile(Object("EnemyProjectile", Transform(transform.GetPosition() + Vector3(5.0f, 25.f, .0f), Vector3(), Vector3(16.f, 16.f, 1.f)))));
		cooldownShoot = 0.f;
	}
	myRigidBody2D->AddVelocity(Vector2( 100.f, 0.f));
	Object::Update(deltaTime);
}

void Loner::UpdateRender()
{
	Object::UpdateRender();
}
