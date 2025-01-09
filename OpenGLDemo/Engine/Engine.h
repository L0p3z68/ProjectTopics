#pragma once
#include "Window.h"
#include "Vector2.h"
#include <vector>

class Engine
{
	private:
		static Engine* instance;
		struct b2WorldId* worldId = nullptr;

		Window* window;
		struct Aux;
		Aux* aux;
		bool isRunning = true;
		int prevTime = 0;
		int currentTime = 0;
		float deltaTime = 0;

		Engine(Window* window, Vector2 gravity);

	public:
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;

		static Engine* GetInstance(Window* window = nullptr, Vector2 gravity = Vector2(.0f, .0f));

		void StartEngine();
		int GetTicks();
		int GetEventPool();
		b2WorldId* GetWorldId();


		~Engine();
};

