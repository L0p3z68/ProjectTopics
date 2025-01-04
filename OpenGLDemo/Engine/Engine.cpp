#include "Engine.h"
#include <SDL.h>

struct Engine::Aux
{
	SDL_Event ev;

};

Engine::Engine(): aux(new Aux())
{
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
