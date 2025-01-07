#include "Engine.h"
#include <SDL.h>

Engine* Engine::instance = nullptr;

struct Engine::Aux
{
	SDL_Event ev;

};

Engine::Engine(Window* window): aux(new Aux()), window(window)
{
}

Engine* Engine::GetInstance(Window* window) 
{
	if (instance == nullptr)
	{
		if (window == nullptr)
		{
			throw std::runtime_error("Cannot initialize Engine without a Window instance");
		}
		instance = new Engine(window);
	}
	return instance;
}

void Engine::StartEngine()
{
	window->Awake();
	window->Start();
	while (isRunning) {
		prevTime = currentTime;
		currentTime = GetTicks();
		deltaTime = (currentTime - prevTime) / 1000.0f;
		while (GetEventPool() != 0)
		{
			// Getting the events
			if (aux->ev.type == SDL_QUIT)
				isRunning = false;

		}
		window->Update(deltaTime);
	}
	this->~Engine();
}

int Engine::GetTicks()
{
	return SDL_GetTicks();
}

int Engine::GetEventPool()
{
	return SDL_PollEvent(&aux->ev);
}

Engine::~Engine()
{
	window->~Window();
	delete aux;
}
