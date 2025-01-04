#include "Engine.h"
#include <SDL.h>

struct Engine::Aux
{
	SDL_Event ev;

};

Engine::Engine(): aux(new Aux())
{
}

void Engine::AddScene(Scene scene)
{
	scenes.push_back(scene);
}

void Engine::Awake()
{
	for (size_t i = 0; i < scenes.size(); i++)
	{
		scenes[i].Awake();
	}
}

void Engine::Start()
{
	for (size_t i = 0; i < scenes.size(); i++)
	{
		scenes[i].Start();
	}
}

void Engine::Update(int deltaTime)
{
	for (size_t i = 0; i < scenes.size(); i++)
	{
		scenes[i].Update(deltaTime);
	}
}

int Engine::GetTicks()
{
	return SDL_GetTicks();
}

bool Engine::IsGameQuit()
{
	return aux->ev.type == SDL_QUIT;
}

int Engine::GetEventPool()
{
	return SDL_PollEvent(&aux->ev);
}

Engine::~Engine()
{
}
