#pragma once
#include "BaseScript.h"
#include "Transform.h"
#include <vector>
class Object : BaseScript
{
	private:
		Transform tranform;
		std::vector<Components> components;

	public:
		Object(Transform tranform);
		void AddComponent(Components component);

		void Awake();
		void Start();
		void Update(int deltaTime);

		~Object();
};

