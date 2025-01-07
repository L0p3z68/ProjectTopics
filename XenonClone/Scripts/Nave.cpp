#include "Nave.h"

Nave::Nave(Object nav): Object(nav)
{
	Window* window = Window::GetInstance();
	spriteNave = new SpriteRenderer("graphics/Ship1.bmp", window, 7, 1, 3, this);
	animatorNave = new Animator(spriteNave);
	moveSpeed = 200.0f;
	isMovingLeft = false;
	isMovingRight = false;
}

void Nave::Awake()
{
	AddComponent(spriteNave);
	AddComponent(animatorNave);

	animatorNave->AddAnimation("GoLeft", { 3, 2, 1, 0 }, false, 10.f);
	animatorNave->AddAnimation("GoCenterFromLeft", { 1, 2, 3 }, false, 10.f);
	animatorNave->AddAnimation("Idle", { 3 }, false, 1.f);
	animatorNave->AddAnimation("GoRight", { 3, 4, 5, 6 }, false, 10.f);
	animatorNave->AddAnimation("GoCenterFromRight", { 5, 4, 3 }, false, 10.f);

	Object::Awake();
}

void Nave::Start()
{
	animatorNave->Play("Idle");

	Object::Start();
}

void Nave::Update(float deltaTime)
{
	if (input.GetKeyState(input.right))
	{
		AddToPosition(Vector3(moveSpeed * deltaTime, 0.f, 0.f));
		if (!isMovingRight)
		{
			animatorNave->Play("GoRight");
		}
		isMovingRight = true;
		isMovingLeft = false;
	}
	else if (input.GetKeyState(input.left))
	{
		AddToPosition(Vector3(-moveSpeed * deltaTime, 0.f, 0.f));
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

	if (input.GetKeyState(input.up))
	{
		AddToPosition(Vector3(0.f, -moveSpeed * deltaTime, 0.f));
	}
	else if (input.GetKeyState(input.down))
	{
		AddToPosition(Vector3(0.f, moveSpeed * deltaTime, 0.f));
	}

	Object::Update(deltaTime);
}
