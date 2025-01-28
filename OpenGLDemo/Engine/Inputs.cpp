#include "Inputs.h"
#include <SDL.h>

struct Inputs::Aux
{
	const Uint8* keyState;
	SDL_GameController* controller = nullptr;
};

Inputs::Inputs() : aux(new Aux())
{
	if (SDL_NumJoysticks() > 0) {
		for (int i = 0; i < SDL_NumJoysticks(); ++i) {
			if (SDL_IsGameController(i)) {  // Check if the joystick is recognized as a game controller
				aux->controller = SDL_GameControllerOpen(i);  // Open the controller
				if (aux->controller) {
					std::cout << "Controller connected: " << SDL_GameControllerName(aux->controller) << std::endl;
					break;
				}
				else {
					std::cerr << "Could not open controller: " << SDL_GetError() << std::endl;
				}
			}
		}
	}
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

bool Inputs::GetButtonState(ButtonName buttonName)
{
	switch (buttonName) 
	{
		case FaceDown:
			return SDL_GameControllerGetButton(aux->controller, SDL_CONTROLLER_BUTTON_A);
		case FaceLeft:
			return SDL_GameControllerGetButton(aux->controller, SDL_CONTROLLER_BUTTON_X);
		case FaceUp:
			return SDL_GameControllerGetButton(aux->controller, SDL_CONTROLLER_BUTTON_Y);
		case FaceRight:
			return SDL_GameControllerGetButton(aux->controller, SDL_CONTROLLER_BUTTON_B);
		default:
			return SDL_GameControllerGetButton(aux->controller, SDL_CONTROLLER_BUTTON_INVALID);
	}
}

Vector2 Inputs::GetControllerLeftAxis()
{
	if (aux->controller) {
		return Vector2(SDL_GameControllerGetAxis(aux->controller, SDL_CONTROLLER_AXIS_LEFTX), SDL_GameControllerGetAxis(aux->controller, SDL_CONTROLLER_AXIS_LEFTY) + 1);
	}
	return Vector2();
}

Vector2 Inputs::GetControllerRightAxis()
{
	if (aux->controller) {
		return Vector2(SDL_GameControllerGetAxis(aux->controller, SDL_CONTROLLER_AXIS_RIGHTX), SDL_GameControllerGetAxis(aux->controller, SDL_CONTROLLER_AXIS_RIGHTY));
	}
	return Vector2();
}

