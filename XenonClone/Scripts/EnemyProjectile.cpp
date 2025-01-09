#include "EnemyProjectile.h"
#include "Explotion.h"

EnemyProjectile::EnemyProjectile(Object nav) : Object(nav)
{
	Window* window = Window::GetInstance();
	myRigidBody2D = new RigidBody2D(this, true, true);
	mySpriteRenderer = new SpriteRenderer("graphics/EnWeap6.bmp", window, 8, 1, 0, this);
	myAnimator = new Animator(mySpriteRenderer);
}

void EnemyProjectile::Awake()
{
	AddComponent(myRigidBody2D);
	AddComponent(mySpriteRenderer);

	myAnimator->AddAnimation("Idle", { 0, 1, 2, 3, 4, 5, 6, 7 }, true, 10.f);

	AddComponent(myAnimator);

	Object::Awake();
}

void EnemyProjectile::Start()
{
	myAnimator->Play("Idle");

	Object::Start();
}

void EnemyProjectile::Update(float deltaTime)
{
	myRigidBody2D->AddVelocity(Vector2(.0f, 100.f));
	timeToDie += deltaTime;
	if (timeToDie > 10.f) {
		Destroy();
	}
	Object::Update(deltaTime);
}

void EnemyProjectile::UpdateRender()
{
	Object::UpdateRender();
}

void EnemyProjectile::OnTrigger(Object* object)
{
	if (object->GetTag() == "Nave") {
		Instantiate(new Explotion(Object("", transform)));
		Destroy();
	}
}


