#pragma once
#include "Object.h"
#include <vector>

class Scene : public BaseScript
{
	private:
		std::vector<Object*> objectsInScene;

	public:
		Scene();
		void AddObject(Object* object);
		void Awake();
		void Start();
		void Update(float deltaTime);
		void UpdateRender();
		void Destroy(Object* object);

		~Scene();
};

