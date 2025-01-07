#include "Inputs.h"
#include <SDL.h>

struct Inputs::Aux
{
	const Uint8* keyState;
};

Inputs::Inputs() : aux(new Aux())
{
}

bool Inputs::GetKeyState(KeyName keyName)
{
	aux->keyState = SDL_GetKeyboardState(NULL);
		switch (keyName)
	{
		case space:
			return aux->keyState[SDL_SCANCODE_SPACE];

		case up:
			return aux->keyState[SDL_SCANCODE_UP];
		case down:
			return aux->keyState[SDL_SCANCODE_DOWN];
		case left:
			return aux->keyState[SDL_SCANCODE_LEFT];
		case right:
			return aux->keyState[SDL_SCANCODE_RIGHT];
		case w:
			return aux->keyState[SDL_SCANCODE_W];
		case s:
			return aux->keyState[SDL_SCANCODE_S];
		case a:
			return aux->keyState[SDL_SCANCODE_A];
		case d:
			return aux->keyState[SDL_SCANCODE_D];
		default:
			return aux->keyState[SDL_SCANCODE_UNKNOWN];
	}
}
