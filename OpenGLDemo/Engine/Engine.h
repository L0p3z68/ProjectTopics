#pragma once
#include "Scene.h"

#include <vector>

class Engine
{
	private:
		std::vector<Scene> scenes;
		struct Aux;
		Aux* aux;

	public:
		Engine();
		int GetTicks();
		bool IsGameQuit();
		int GetEventPool();

		~Engine();
};

