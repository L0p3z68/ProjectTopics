#include "SceneGame.h"
#include "Engine/SpriteRenderer.h"
#include "Engine/Animator.h"	

SceneGame::SceneGame() :
	Scene(),
	nave(new Nave(Object("Nave", Transform(Vector3(40.f, 420.f, .0f), Vector3(), Vector3(64.f, 64.f, 1.f))))),
	backGround(new BackGround(Object())),
	boundarie(new Boundaries(Object("boundarie", Transform(Vector3(-5.0f, 0.0f, 0.0f), Vector3(), Vector3(5.0f, 1400.0f, 1.0f))))),
	boundarie1(new Boundaries(Object("boundarie", Transform(Vector3(1005.0f, 0.0f, 0.0f), Vector3(), Vector3(5.0f, 1400.0f, 1.0f))))),
	boundarie2(new Boundaries(Object("boundarie", Transform(Vector3(0.0f, -10.0f, 0.0f), Vector3(), Vector3(5000.0f, 5.0f, 1.0f))))),
	boundarie3(new Boundaries(Object("boundarie", Transform(Vector3(0.0f, 700.0f, 0.0f), Vector3(), Vector3(5000.0f, 5.0f, 1.0f))))),
	spawner(new Spawners(Object("Spawner", Transform()))),
	backgroundParalax(new BackgroundParalax(Object(" ", Transform(Vector3(300.f, 420.f, .0f), Vector3(), Vector3(576.f, 192.f, 1.f))))),
	backgroundParalax2(new BackgroundParalax(Object(" ", Transform(Vector3(700.f, 20.f, .0f), Vector3(), Vector3(576.f, 192.f, 1.f)))))
{
}

void SceneGame::Awake()
{
	// Order of load in scene
	AddObject(backGround);
	AddObject(backgroundParalax);
	AddObject(backgroundParalax2);
	AddObject(nave);
	AddObject(boundarie);
	AddObject(boundarie1);
	AddObject(boundarie2);
	AddObject(spawner);

	Scene::Awake();
}

void SceneGame::Start()
{
	Scene::Start();
}

void SceneGame::Update(float deltaTime) 
{
	Scene::Update(deltaTime);
}
