#include "Spawners.h"
#include "Loner.h"
#include "Rusher.h"

Spawners::Spawners(Object nav): Object(nav)
{
}

void Spawners::Awake()
{
	Object::Awake();
}

void Spawners::Start()
{
	Object::Start();
}

void Spawners::Update(float deltaTime)
{
	cooldownLoner += deltaTime;
	cooldownRusher += deltaTime;
	if (cooldownLoner > 8.0f) {
		Instantiate(new Loner(Object("Enemy", Transform(Vector3(-20.f, 120.f, .0f), Vector3(), Vector3(64.f, 64.f, 1.f)))));
		cooldownLoner = 0.f;
	}
	if (cooldownRusher > 6.f) {
		Instantiate(new Rusher(Object("Enemy", Transform(Vector3(200.f, -20.f, .0f), Vector3(), Vector3(64.f, 64.f, 1.f)))));
		Instantiate(new Rusher(Object("Enemy", Transform(Vector3(600.f, -20.f, .0f), Vector3(), Vector3(64.f, 64.f, 1.f)))));
		Instantiate(new Rusher(Object("Enemy", Transform(Vector3(800.f, -20.f, .0f), Vector3(), Vector3(64.f, 64.f, 1.f)))));
		cooldownRusher = 0.f;
	}
	Object::Update(deltaTime);
}

void Spawners::UpdateRender()
{
	Object::UpdateRender();
}
