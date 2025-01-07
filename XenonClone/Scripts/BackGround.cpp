#include "BackGround.h"

BackGround::BackGround(Object background): Object(background)
{
	Window* window = Window::GetInstance();
	mySpriteRenderer = new SpriteRenderer("graphics/galaxy2.bmp", window);
}

void BackGround::Awake()
{
	AddComponent(mySpriteRenderer);
	Object::Awake();
}

void BackGround::Start()
{
	Object::Start();
}

void BackGround::Update(float deltaTime)
{
	Object::Update(deltaTime);
}
