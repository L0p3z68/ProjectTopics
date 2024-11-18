#pragma once
#include "BaseScript.h"
#include "Transform.h"
#include <vector>

class Object : BaseScript
{
	private:
		Transform transform;
		std::vector<Components> components;

	public:
		Object(Transform transform);
		Object();
		void AddComponent(Components component);

		void Awake();
		void Start();
		void Update(int deltaTime);

		~Object();
};

