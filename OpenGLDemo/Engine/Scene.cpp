#include "Scene.h"

Scene::Scene()
{
}

void Scene::AddObject(Object object)
{
	objectsInScene.push_back(object);
}

void Scene::Awake()
{
	for (size_t i = 0; i < objectsInScene.size(); ++i)
	{
		objectsInScene[i].Awake();
	}
}

void Scene::Start()
{
	for (size_t i = 0; i < objectsInScene.size(); ++i)
	{
		objectsInScene[i].Start();
	}
}

void Scene::Update(int deltaTime)
{
	for (size_t i = 0; i < objectsInScene.size(); ++i)
	{
		objectsInScene[i].Update(deltaTime);
	}
}

Scene::~Scene()
{
	objectsInScene.~vector();
}
