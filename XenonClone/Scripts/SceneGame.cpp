#include "SceneGame.h"
#include "Engine/SpriteRenderer.h"
#include "Engine/Animator.h"	

SceneGame::SceneGame() : 
	Scene(), 
	nave(new Nave(Transform(Vector3(16.f, 420.f, 0.f), Vector3(), Vector3(64.f, 64.f, 1.f)))),
	backGround(new BackGround(Object()))
{
}

void SceneGame::Awake()
{
	// Order of load in scene
	AddObject(backGround);
	AddObject(nave);

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
