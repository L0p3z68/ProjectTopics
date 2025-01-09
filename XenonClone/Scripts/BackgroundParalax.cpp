#include "BackgroundParalax.h"

BackgroundParalax::BackgroundParalax(Object nav) : Object(nav)
{
	Window* window = Window::GetInstance();
	mySpriteRenderer = new SpriteRenderer("graphics/Blocks.bmp", window, 1, 1, 0, this);
}

void BackgroundParalax::Awake()
{
	AddComponent(mySpriteRenderer);
	Object::Awake();
}

void BackgroundParalax::Start()
{
	Object::Start();
}

void BackgroundParalax::Update(float deltaTime)
{
	if (transform.GetPosition().Y > 900) {
		transform.SetPosition(Vector3(transform.GetPosition().X, -90.f, .0f));
	}
	transform.SetPosition(transform.GetPosition() + Vector3(.0f, 1.f, 0.f));
	Object::Update(deltaTime);
}

void BackgroundParalax::UpdateRender()
{
	Object::UpdateRender();
}
