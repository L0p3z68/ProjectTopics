#pragma once
#include "Window.h"
#include <vector>

class Engine
{
	private:
		static Engine* instance;

		Window* window;
		struct Aux;
		Aux* aux;
		bool isRunning = true;
		int prevTime = 0;
		int currentTime = 0;
		float deltaTime = 0;

		Engine(Window* window);

	public:
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;

		static Engine* GetInstance(Window* window = nullptr);

		void StartEngine();
		int GetTicks();
		int GetEventPool();


		~Engine();
};

