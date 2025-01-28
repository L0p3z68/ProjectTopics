#include "Scene.h"

Scene::Scene()
{
}

void Scene::AddObject(Object* object)
{
	objectsInScene.push_back(object);
	object->SetScene(this);
}

void Scene::Awake()
{
	for (size_t i = 0; i < objectsInScene.size(); ++i)
	{
		objectsInScene[i]->Awake();
	}
}

void Scene::Start()
{
	for (size_t i = 0; i < objectsInScene.size(); ++i)
	{
		objectsInScene[i]->Start();
	}
}

void Scene::Update(float deltaTime)
{
	for (size_t i = 0; i < objectsInScene.size(); ++i)
	{
		objectsInScene[i]->Update(deltaTime);
	}
}

void Scene::UpdateRender()
{
	for (size_t i = 0; i < objectsInScene.size(); ++i)
	{
		objectsInScene[i]->UpdateRender();
	}
}

void Scene::Destroy(Object* object)
{
	for (size_t i = 0; i < objectsInScene.size(); ++i)
	{
		if (objectsInScene[i] == object) 
		{
			objectsInScene.erase(objectsInScene.begin() + i);
			object->~Object();
			return;
		}
	}
}

Scene::~Scene()
{
	objectsInScene.~vector();
}
