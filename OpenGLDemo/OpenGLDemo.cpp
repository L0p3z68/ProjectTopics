#include <iostream>
#include <SDL.h>
#include "Animator.h"

#include <glad/glad.h>
#include "stb_image.h"
#include <box2d.h>
#include "Window.h"
#include "SpriteRenderer.h"
#undef main

/*int main(int argc, char* argv[])
{
	SDL_Rect playerPosition;
	playerPosition.x = 16;
	playerPosition.w = playerPosition.h = 32;
	int indexAnim = 0;

	float frameTime = 0;
	int prevTime = 0;
	int currentTime = 0;
	float deltaTime = 0;

	float moveSpeed = 200.0f;
	const Uint8* keyState;

	SDL_Init(SDL_INIT_VIDEO);
	Scene scene;
	Window window = Window("SDL window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL, scene);
	SpriteRenderer currentImage = SpriteRenderer("graphics/Ship1.bmp", window.GetRenderTarget(), 7, 1);
	SpriteRenderer background = SpriteRenderer("graphics/galaxy2.bmp", window.GetRenderTarget());
	playerPosition.y = 420;

	indexAnim = 3;
	
	SDL_SetRenderDrawColor(window.GetRenderTarget(), 0xFF, 0, 0, 0xFF);

	bool isRunning = true;
	SDL_Event ev;

	while (isRunning)
	{
		prevTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - prevTime) / 1000.0f;

		while (SDL_PollEvent(&ev) != 0)
		{
			// Getting the events
			if (ev.type == SDL_QUIT)
				isRunning = false;
			else if (ev.type == SDL_KEYUP)
			{
				indexAnim = 3;
			}
		}

		keyState = SDL_GetKeyboardState(NULL);
		if (keyState[SDL_SCANCODE_RIGHT]) {
			playerPosition.x += moveSpeed * deltaTime;

			if (frameTime >= 0.1f)
			{
				frameTime = 0;
				if (indexAnim <= 5) {
					indexAnim++;
				}
			}
			
		}
		else if (keyState[SDL_SCANCODE_LEFT]) {
			playerPosition.x -= moveSpeed * deltaTime;

			if (frameTime >= 0.1f)
			{
				frameTime = 0;
				if (indexAnim >= 1) {
					indexAnim--;
				}
			}
			
		}

		if (keyState[SDL_SCANCODE_UP]) 
		{
			playerPosition.y -= moveSpeed * deltaTime;
		}
		else if (keyState[SDL_SCANCODE_DOWN])
		{
			playerPosition.y += moveSpeed * deltaTime;
		}
		
		frameTime += deltaTime;

		if (frameTime >= 0.25f)
		{
			frameTime = 0;
			playerRect.x += frameWidth;
			if (playerRect.x >= textureWidth) {
				playerRect.x = 0;
				playerRect.y += frameHeight;
				if (playerRect.y >= textureHeight) {
					playerRect.y = 0;
				}
			}
		}

		SDL_RenderClear(window.GetRenderTarget());
		background.RenderImage();
		currentImage.RenderImage(&playerPosition, indexAnim);
		SDL_RenderPresent(window.GetRenderTarget());
	}

	window.~Window();
	currentImage.~SpriteRenderer();
	background.~SpriteRenderer();

	SDL_Quit();

	return 0;
}*/