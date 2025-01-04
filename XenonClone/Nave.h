#pragma once
#include "Object.h"
#include <SDL.h>

class Nave : Object
{
	private:
		Transform transform;
		std::vector<Components> components;
	public:
		Nave(SDL_Renderer targetRender);
};

