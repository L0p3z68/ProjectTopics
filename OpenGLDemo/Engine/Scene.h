#pragma once
#include "Object.h"
#include <vector>

class Scene : BaseScript
{
	private:
		std::vector<Object> objectsInScene;

	public:
		Scene();
		void AddObject(Object object);
		void Awake();
		void Start();
		void Update(int deltaTime);

		~Scene();
};

