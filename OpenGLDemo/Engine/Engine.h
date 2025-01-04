#pragma once
#include "Scene.h"

#include <vector>

class Engine : public BaseScript
{
	private:
		std::vector<Scene> scenes;
		struct Aux;
		Aux* aux;

	public:
		Engine();
		void AddScene(Scene scene);
		void Awake();
		void Start();
		void Update(int deltaTime);
		int GetTicks();
		bool IsGameQuit();
		int GetEventPool();

		~Engine();
};

