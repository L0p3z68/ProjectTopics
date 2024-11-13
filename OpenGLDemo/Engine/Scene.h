#pragma once
#include "BaseScript.h"
#include <vector>

class Scene : BaseScript
{
	private:
		std::vector<BaseScript> objectsInScene;

	public:
		Scene();
		void AddObject(BaseScript object);
		void Awake();
		void Start();
		void Update(int deltaTime);

		~Scene();
};

