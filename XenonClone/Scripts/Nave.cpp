#include "Nave.h"
#include "Missiles.h"

Nave::Nave(Object nav): Object(nav)
{
	Window* window = Window::GetInstance();
	myRigidBody2D = new RigidBody2D(this, true, false);
	spriteNave = new SpriteRenderer("graphics/Ship1.bmp", window, 7, 1, 3, this);
	animatorNave = new Animator(spriteNave);
	moveSpeed = 200.0f;
	isMovingLeft = false;
	isMovingRight = false;
}

void Nave::Awake()
{
	AddComponent(myRigidBody2D);
	AddComponent(spriteNave);

	animatorNave->AddAnimation("GoLeft", { 3, 2, 1, 0 }, false, 10.f);
	animatorNave->AddAnimation("GoCenterFromLeft", { 1, 2, 3 }, false, 10.f);
	animatorNave->AddAnimation("Idle", { 3 }, false, 1.f);
	animatorNave->AddAnimation("GoRight", { 3, 4, 5, 6 }, false, 10.f);
	animatorNave->AddAnimation("GoCenterFromRight", { 5, 4, 3 }, false, 10.f);


	AddComponent(animatorNave);

	Object::Awake();
}

void Nave::Start()
{
	animatorNave->Play("Idle");

	Object::Start();
}

void Nave::Update(float deltaTime)
{
	Vector2 moveVec = Vector2();

	if (input.GetKeyState(input.right))
	{
		moveVec = moveVec + Vector2(1.f, .0f);
	}
	else if (input.GetKeyState(input.left))
	{
		moveVec = moveVec + Vector2(-1.f, .0f);
	}

	if (input.GetKeyState(input.up))
	{
		moveVec = moveVec + Vector2(.0f, -1.0f);
	}
	else if (input.GetKeyState(input.down))
	{
		moveVec = moveVec + Vector2(.0f, 1.0f);
	}

	if (input.GetControllerLeftAxis() != Vector2()) {
		moveVec = input.GetControllerLeftAxis();
	}
	cooldownBullet += deltaTime;
	if ((input.GetKeyState(input.space) || input.GetButtonState(input.FaceDown)) && cooldownBullet > .2f) {
		Instantiate(new Missiles(Object("Missiles", Transform(transform.GetPosition() + Vector3(5.0f, -25.f, .0f), Vector3(), Vector3(16.f, 16.f, 1.f)))));
		std::cout << deltaTime << std::endl;
		cooldownBullet = .0f;
	}

	if (moveVec.GetX() > 0) 
	{
		if (!isMovingRight)
		{
			animatorNave->Play("GoRight");
		}
		isMovingRight = true;
		isMovingLeft = false;
	}
	else if(moveVec.GetX() < 0) 
	{
		if (!isMovingLeft)
		{
			animatorNave->Play("GoLeft");
		}
		isMovingRight = false;
		isMovingLeft = true;
	}
	else {
		if (isMovingLeft) {
			animatorNave->Play("GoCenterFromLeft");
			isMovingLeft = false;
		}
		if (isMovingRight) {
			animatorNave->Play("GoCenterFromRight");
			isMovingRight = false;
		}
	}

	myRigidBody2D->AddVelocity(moveVec.Normalize() * moveSpeed);
	Object::Update(deltaTime);
}

void Nave::UpdateRender()
{
	Object::UpdateRender();
}

void Nave::OnTrigger(Object* object)
{
	if (object->GetTag() == "EnemyProjectile") {
		object->OnTrigger(this);
	}
	
}
